// Copyright (C) Massive Miniteam GmbH 2020


#include "AnimationImporter.h"

#include "AnimationUtils.h"
#include "AssetToolsModule.h"
#include "ContentBrowserModule.h"
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"

#include "Widgets/Notifications/SNotificationList.h"
#include "Framework/Notifications/NotificationManager.h"
#include "EditorAssetLibrary.h"
#include "IContentBrowserSingleton.h"
#include "Misc/MessageDialog.h"

#include "PackageHelperFunctions.h"
#include "Animation/AnimMontage.h"
#include "Animation/AnimNotifies/AnimNotify_PlayParticleEffect.h"
#include "Animation/AnimNotifies/AnimNotify_PlaySound.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/ObjectLibrary.h"
#include "Factories/AnimMontageFactory.h"
#include "Factories/CurveFactory.h"
#include "Interfaces/ITargetPlatformModule.h"
#include "StaticMeshAnimationContainer.h"
#include "UObject/SavePackage.h"
#include "AnimNotify_PlayNiagaraEffect.h"
#include "AnimNotify_PlayForceFeedbackEffect.h"
#include "StaticMeshEffectTrack.h"
#include "Curves/CurveVector.h"
#include "GameFramework/ForceFeedbackAttenuation.h"
#include "Niagara/Classes/NiagaraSystem.h"

bool UAnimationImporter::Initialize()
{
	return Super::Initialize();
}

UAnimMontage* UAnimationImporter::CreateAnimationMontage(UAnimSequence* AnimSequence)
{
	FString FileName = AnimSequence->GetName();
	FileName.RemoveAt(0, 2);
	
	FString Left, Right;

	int lastSlashIndex;
	FString SaveToFolderPath(AnimSequence->GetPathName());
	SaveToFolderPath.FindLastChar('/', lastSlashIndex);
	SaveToFolderPath = SaveToFolderPath.LeftChop(SaveToFolderPath.Len() - lastSlashIndex - 1);
	
	return CreateMontageFile(AnimSequence, SaveToFolderPath, FileName);
}

UAnimMontage* UAnimationImporter::CreateMontageFile(UAnimSequence* AnimSequence, FString SaveToFolderPath, FString FileName) const
{
	FString MontageFileName = "AM_" + FileName;
	SaveToFolderPath = SaveToFolderPath + MontageFileName;

	if (UEditorAssetLibrary::DoesAssetExist(*SaveToFolderPath))
	{
		ShowEngineDialog(
			TEXT("There is already an animation montage with the same name (" + FileName +") in the specified folder."),
			TEXT("WARNING"));
		return nullptr;
	}

	UPackage* PackageNew = CreatePackage(*SaveToFolderPath);
	UAnimMontageFactory* AnimMontageFactory = NewObject<UAnimMontageFactory>();
	AnimMontageFactory->SourceAnimation = AnimSequence;

	UObject* CreatedAsset = AnimMontageFactory->FactoryCreateNew(UAnimMontage::StaticClass(), PackageNew, FName(*MontageFileName),
		RF_Public | RF_Standalone, NULL, GWarn);

	FAssetRegistryModule::AssetCreated(CreatedAsset);
	UAnimMontage* AnimMontage = Cast<UAnimMontage>(CreatedAsset);

	if (CreatedAsset != nullptr)
	{
		FString const PackageName = PackageNew->GetName();
		FString const PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

		FSavePackageArgs SaveArgs = { nullptr /* deprecated target platform */, nullptr, RF_Public | RF_Standalone, SAVE_NoError, false, true, true, FDateTime::MinValue(), GError };
		UPackage::Save(PackageNew, NULL, *PackageFileName, SaveArgs);
		
		CreatedAsset->MarkPackageDirty();
		PackageNew->SetDirtyFlag(true);
	}

	UE_LOG(LogTemp, Log, TEXT("Animation Montage file created"));
	return AnimMontage;
}

FName UAnimationImporter::GetFirstAndOnlyTrackName(UAnimSequence* AnimSequence)
{
	ITargetPlatformManagerModule* TargetPlatformManager = GetTargetPlatformManager();
	auto TargetPlatform = TargetPlatformManager->GetTargetPlatforms()[0];
	FCompressibleAnimData AnimData(AnimSequence, false, TargetPlatform);
	AnimData.FetchData(TargetPlatform);

	if (AnimData.BoneData.Num() == 1)
	{
		return AnimData.BoneData[0].Name;
	}
	
	return "";
}

void UAnimationImporter::ShowNotifyInfo(const FString& Message) const
{
	FNotificationInfo NotifyInfo(FText::FromString(Message));
	NotifyInfo.bUseLargeFont = true;
	NotifyInfo.FadeOutDuration = 2.f;
	NotifyInfo.ExpireDuration = 8.f;

	FSlateNotificationManager::Get().AddNotification(NotifyInfo);
}

void UAnimationImporter::ShowEngineDialog(const FString& Message, const FString& OptTitle) const
{
	FText MsgTitle = FText::FromString(OptTitle);
	FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(Message), MsgTitle);
}

UStaticMeshEffectTrack* UAnimationImporter::CreateStaticMeshEffectTrackAsset(FString Name, FString TargetPath)
{
	UPackage* PackageNew = CreatePackage(*(TargetPath + Name));

	UStaticMeshEffectTrack* Obj = NewObject<UStaticMeshEffectTrack>(PackageNew, UStaticMeshEffectTrack::StaticClass(), *Name, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone);
	FAssetRegistryModule::AssetCreated(Obj);
	
	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

	if (Obj != nullptr)
	{
		FString const PackageName = PackageNew->GetName();
		FString const PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

		FSavePackageArgs SaveArgs = { nullptr /* deprecated target platform */, nullptr, RF_Public | RF_Standalone, SAVE_NoError, false, true, true, FDateTime::MinValue(), GError };
		UPackage::Save(PackageNew, NULL, *PackageFileName, SaveArgs);
		Obj->MarkPackageDirty();
		PackageNew->SetDirtyFlag(true);
		
		AssetRegistry.AssetCreated(Obj);

		TArray<UObject*> Objects;
		Objects.Add(Obj);
		ContentBrowserModule.Get().SyncBrowserToAssets(Objects);
	}
	
	return Obj;
}

UCurveVector* UAnimationImporter::CreateCurveAsset(FString Name, FString TargetPath)
{
	FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");
	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

	FString PackageName = TargetPath + Name;
	const FString PackagePath = FPackageName::GetLongPackagePath(PackageName);

	UCurveVectorFactory* Factory = NewObject<UCurveVectorFactory>(UCurveVectorFactory::StaticClass());
	UCurveVector* Curve = LoadObject<UCurveVector>(nullptr, *FString::Printf(TEXT("%s.%s"), *PackageName, *Name));

	if (Curve == nullptr)
	{
		UPackage* Package = CreatePackage(*PackageName);
		Curve = Cast<UCurveVector>(AssetToolsModule.Get().CreateAsset(Name, PackagePath, UCurveVector::StaticClass(), Factory));

		FSavePackageArgs SaveArgs = { nullptr /* deprecated target platform */, nullptr, RF_Public | RF_Standalone, SAVE_NoError, false, true, true, FDateTime::MinValue(), GError };
		UPackage::Save(Package, Curve, *FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension()), SaveArgs);

		AssetRegistry.AssetCreated(Curve);

		TArray<UObject*> Objects;
		Objects.Add(Curve);
		ContentBrowserModule.Get().SyncBrowserToAssets(Objects);
	}

	return Curve;
}

void UAnimationImporter::ImportAudioTrack(UAnimMontage* Montage, FString TrackName, UStaticMeshAnimationContainer* Container)
{
	if (TrackName.Len() == 0)
	{
		return;
	}
	
	for (FStaticMeshAnimationItem& Item : Container->AnimationItems)
	{
		if (Item.ComponentName == TrackName)
		{
			if (!IsValid(Item.EffectTrack))
			{
				FString DataAssetName = Montage->GetName().Replace(TEXT("AM_"), TEXT("ET_"));

				FString FileName = Montage->GetName();
				FileName.RemoveAt(0, 2);
	
				FString Left, Right;
				int lastSlashIndex;
				FString SaveToFolderPath(Montage->GetPathName());
				SaveToFolderPath.FindLastChar('/', lastSlashIndex);
				SaveToFolderPath = SaveToFolderPath.LeftChop(SaveToFolderPath.Len() - lastSlashIndex - 1);
				Item.EffectTrack = CreateStaticMeshEffectTrackAsset(DataAssetName, SaveToFolderPath);
			}

			Item.EffectTrack->AudioItems.Reset();
			Item.EffectTrack->VisualItems.Reset();
			Item.EffectTrack->ForceFeedbackItems.Reset();

			FAnimNotifyContext AnimNotifies;
			Montage->GetAnimNotifies(-0.1, Montage->GetPlayLength(), AnimNotifies);
			for (auto NotifyItem : AnimNotifies.ActiveNotifies)
			{
				auto Notify = NotifyItem.GetNotify();
				if (const UAnimNotify_PlaySound* PlaySound = Cast<UAnimNotify_PlaySound>(Notify->Notify))
				{
					FStaticMeshAudioEffectTrackItem TrackItem;
					TrackItem.SoundCue = PlaySound->Sound;
					TrackItem.DelayInSeconds = Notify->GetTriggerTime();
					TrackItem.bStartStopOnce = PlaySound->Sound->IsLooping();
					Item.EffectTrack->AudioItems.Add(TrackItem);
				}
				if (const UAnimNotify_PlayForceFeedbackEffect* PlayForceFeedback = Cast<UAnimNotify_PlayForceFeedbackEffect>(Notify->Notify))
				{
					FStaticMeshForceFeedbackTrackItem TrackItem;
					TrackItem.ForceFeedbackEffect = PlayForceFeedback->ForceFeedbackEffect;
					TrackItem.AttenuationSettings = PlayForceFeedback->AttenuationSettings;
					TrackItem.AudioAsVibration = PlayForceFeedback->AudioAsVibration;
					TrackItem.DelayInSeconds = Notify->GetTriggerTime();
					Item.EffectTrack->ForceFeedbackItems.Add(TrackItem);
				}
				if (const UAnimNotify_PlayParticleEffect* PlayParticle = Cast<UAnimNotify_PlayParticleEffect>(Notify->Notify))
				{
					FStaticMeshVisualEffectTrackItem TrackItem;
					//TrackItem.ParticleSystem = PlayParticle->PSTemplate;
					TrackItem.LocationOffset = PlayParticle->LocationOffset;
					TrackItem.RotationOffset = PlayParticle->RotationOffset.Clamp();
					TrackItem.DelayInSeconds = Notify->GetTriggerTime();
					Item.EffectTrack->VisualItems.Add(TrackItem);
				}
				
				if (const UAnimNotify_PlayNiagaraEffect* PlayParticle = Cast<UAnimNotify_PlayNiagaraEffect>(Notify->Notify))
				{
					FStaticMeshVisualEffectTrackItem TrackItem;
					TrackItem.ParticleSystem = PlayParticle->Template;
					TrackItem.LocationOffset = PlayParticle->LocationOffset;
					TrackItem.RotationOffset = PlayParticle->RotationOffset.Clamp();
					TrackItem.DelayInSeconds = Notify->GetTriggerTime();
					Item.EffectTrack->VisualItems.Add(TrackItem);
				}
			}

			Item.EffectTrack->Modify();
		}
	}
}

void UAnimationImporter::AddAngleFromRotKeyTryingToFixGimbalLock(FRichCurve& Curve, float Time, float PreviousAngle, float Angle)
{
	Curve.AddKey(Time, Angle);
}

void UAnimationImporter::ImportStaticMeshAnimation(UAnimSequence* Animation, UAnimMontage* Montage, FString TrackName, UStaticMeshAnimationContainer* Container)
{
	ITargetPlatformManagerModule* TargetPlatformManager = GetTargetPlatformManager();
	auto TargetPlatform = TargetPlatformManager->GetTargetPlatforms()[0];
	FCompressibleAnimData AnimData(Animation, false, TargetPlatform);
	AnimData.FetchData(TargetPlatform);
	
	auto TrackData = AnimData.RawAnimationData;
	FName TargetTrack = FName(TrackName);

	TArray<UPackage*> ToSave;
	ToSave.Add(Container->GetPackage());

	int BoneIndex = 0;
	for (int i = 0; i < AnimData.BoneData.Num(); i++)
	{
		auto BoneData = AnimData.BoneData[i];
		if (BoneData.Name.ToString() == TrackName)
		{
			BoneIndex = i;
		}
	}

	if (BoneIndex < TrackData.Num())
	{
		FRawAnimSequenceTrack Track = TrackData[BoneIndex];
		FString AssetTargetPath = Animation->GetOuter()->GetPathName();
		AssetTargetPath.RemoveFromEnd(Animation->GetName());

		FString BaseName = Animation->GetName();
		BaseName.RemoveFromStart("A");
		BaseName = "VC" + BaseName;

		UCurveVector* PositionCurve = nullptr;
		UCurveVector* RotationCurve = nullptr;
		UCurveVector* ScaleCurve = nullptr;

		if (Track.PosKeys.Num() > 0)
		{
			PositionCurve = CreateCurveAsset(BaseName + "_" + TrackName + "_Position", AssetTargetPath);
			PositionCurve->Modify();
		}

		if (Track.RotKeys.Num() > 0)
		{
			RotationCurve = CreateCurveAsset(BaseName + "_" + TrackName + "_Rotation", AssetTargetPath);
			RotationCurve->Modify();
		}

		if (Track.ScaleKeys.Num() > 0)
		{
			ScaleCurve = CreateCurveAsset(BaseName + "_" + TrackName + "_Scale", AssetTargetPath);
			ScaleCurve->Modify();
		}

		float CurrentTime = 0;
		if (PositionCurve != nullptr)
		{
			PositionCurve->FloatCurves->Reset();
			PositionCurve->FloatCurves[0].Reset();
			PositionCurve->FloatCurves[1].Reset();
			PositionCurve->FloatCurves[2].Reset();
			for (FVector3f Pos : Track.PosKeys)
			{
				PositionCurve->FloatCurves[0].AddKey(CurrentTime, Pos.X);
				PositionCurve->FloatCurves[1].AddKey(CurrentTime, Pos.Y);
				PositionCurve->FloatCurves[2].AddKey(CurrentTime, Pos.Z);

				CurrentTime += 1.0f / Animation->GetSamplingFrameRate().AsDecimal();
			}
		}

		if (RotationCurve != nullptr)
		{
			RotationCurve->FloatCurves->Reset();
			RotationCurve->FloatCurves[0].Reset();
			RotationCurve->FloatCurves[1].Reset();
			RotationCurve->FloatCurves[2].Reset();
			CurrentTime = 0;
			FQuat4f LastQuat;
			for (FQuat4f Quat : Track.RotKeys)
			{
				AddAngleFromRotKeyTryingToFixGimbalLock(RotationCurve->FloatCurves[0], CurrentTime, LastQuat.Euler().X, Quat.Euler().X);
				AddAngleFromRotKeyTryingToFixGimbalLock(RotationCurve->FloatCurves[1], CurrentTime, LastQuat.Euler().Y, Quat.Euler().Y);
				AddAngleFromRotKeyTryingToFixGimbalLock(RotationCurve->FloatCurves[2], CurrentTime, LastQuat.Euler().Z, Quat.Euler().Z);

				LastQuat = Quat;
				CurrentTime += 1.0f / Animation->GetSamplingFrameRate().AsDecimal();
			}
		}

		if (ScaleCurve != nullptr)
		{
			ScaleCurve->FloatCurves->Reset();
			CurrentTime = 0;
			for (FVector3f Scale : Track.ScaleKeys)
			{
				ScaleCurve->FloatCurves[0].AddKey(CurrentTime, Scale.X);
				ScaleCurve->FloatCurves[1].AddKey(CurrentTime, Scale.Y);
				ScaleCurve->FloatCurves[2].AddKey(CurrentTime, Scale.Z);

				CurrentTime += 1.0f / Animation->GetSamplingFrameRate().AsDecimal();
			}
		}

		bool bOverwritten = false;
		for (FStaticMeshAnimationItem& Item : Container->AnimationItems)
		{
			if (Item.ComponentName == TrackName)
			{
				Item.PositionCurve = PositionCurve;
				Item.RotationCurve = RotationCurve;
				Item.ScaleCurve = ScaleCurve;
				Container->Modify();
				bOverwritten = true;
				break;
			}
		}

		if (!bOverwritten)
		{
			FStaticMeshAnimationItem Item;
			Item.ComponentName = TrackName;
			Item.PositionCurve = PositionCurve;
			Item.RotationCurve = RotationCurve;
			Item.ScaleCurve = ScaleCurve;
			Container->AnimationItems.Add(Item);
			Container->Modify();
		}
	}

	ImportAudioTrack(Montage, TrackName, Container);

	for (FStaticMeshAnimationItem& Item : Container->AnimationItems)
	{
		if (Item.ComponentName == TrackName)
		{
			if (Item.PositionCurve != nullptr) ToSave.Add(Item.PositionCurve->GetPackage());
			if (Item.RotationCurve != nullptr) ToSave.Add(Item.RotationCurve->GetPackage());
			if (Item.ScaleCurve != nullptr) ToSave.Add(Item.ScaleCurve->GetPackage());
			if (Item.EffectTrack != nullptr) ToSave.Add(Item.EffectTrack->GetPackage());
			break;
		}
	}

	FEditorFileUtils::PromptForCheckoutAndSave(ToSave, false, /*bPromptToSave=*/ false);
}