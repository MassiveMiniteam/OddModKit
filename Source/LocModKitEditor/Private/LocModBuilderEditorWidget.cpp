// Fill out your copyright notice in the Description page of Project Settings.


#include "LocModBuilderEditorWidget.h"

#include "ModKitEditorSettings.h"
#include <steam/steam_api.h>

#include "AssetExportTask.h"
#include "ISettingsModule.h"
#include "IUATHelperModule.h"
#include "JsonObjectConverter.h"
#include "LocUGCSteamHelper.h"
#include "Exporters/TextureExporterPNG.h"

void ULocModBuilderEditorWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	SteamAPI_Init();
}

TArray<FString> ULocModBuilderEditorWidget::GetModFilesAt(const FString& Path)
{
	TArray<FString> Files;
	IFileManager::Get().FindFilesRecursive(Files, *Path, TEXT("*.pak"), true, false, true);
	IFileManager::Get().FindFilesRecursive(Files, *Path, TEXT("*.utoc"), true, false, false);
	IFileManager::Get().FindFilesRecursive(Files, *Path, TEXT("*.ucas"), true, false, false);
	return Files;
}

FString ULocModBuilderEditorWidget::GetUploadDirForMod(const FString& ModId)
{
	return FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectDir(), "Saved", "StagedMods", "Upload", ModId));
}

void ULocModBuilderEditorWidget::UpdateManifest(const FString& ModId)
{
	FString UploadDir = GetUploadDirForMod(ModId);
	UModKitEditorSettings* ModKitSettings = GetMutableDefault<UModKitEditorSettings>();
	FModKitModDefinition* Definition = ModKitSettings->GetModDefinition(ModId);
	Definition->Manifest.LastUpdated = FString::Printf(TEXT("%lld"), FDateTime::UtcNow().ToUnixTimestamp());
	ModKitSettings->TryUpdateDefaultConfigFile();
			
	FString Json;
	FJsonObjectConverter::UStructToJsonObjectString(Definition->Manifest, Json);
	FFileHelper::SaveStringToFile(Json, *FPaths::Combine(UploadDir, FPaths::SetExtension(ModId, ".manifest")));
}

FString ULocModBuilderEditorWidget::ExportIcon(const FString& ModId)
{
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	FString UploadDir = GetUploadDirForMod(ModId);
	UModKitEditorSettings* ModKitSettings = GetMutableDefault<UModKitEditorSettings>();
	FModKitModDefinition* Definition = ModKitSettings->GetModDefinition(ModId);

	FString Path = FPaths::Combine(UploadDir, FPaths::SetExtension("Icon", ".png"));
	FileManager.DeleteFile(*Path);
	
	UTexture2D* Texture = LoadObject<UTexture2D>(nullptr, *FString::Printf(TEXT("/Game/Mods/%s/Icon"), *ModId));
	if (IsValid(Texture))
	{
		UAssetExportTask* ExportTask = NewObject<UAssetExportTask>();
		ExportTask->Object = Texture;                        // Set the texture to export
		ExportTask->Exporter = UExporter::FindExporter(Texture, TEXT(".PNG")); // Use PNG exporter
		ExportTask->Filename = Path;     // Output file path
		ExportTask->bSelected = false;
		ExportTask->bReplaceIdentical = true;
		ExportTask->bPrompt = false;
		ExportTask->bAutomated = true;
		ExportTask->bUseFileArchive = false;
		UExporter::RunAssetExportTask(ExportTask);
		return Path;
	}

	return "";
}

void ULocModBuilderEditorWidget::BuildMod(const FModKitModDefinition& ModDefinition)
{
	BuildMod_Internal(ModDefinition,[&, ModDefinition](bool bSuccess)
	{
		UpdateManifest(ModDefinition.ModId);
		ExportIcon(ModDefinition.ModId);
		UE_LOG(LogTemp, Log, TEXT("Finished building"));
	});
}

void ULocModBuilderEditorWidget::UploadModToSteam(const FString& ModId, bool bBuildBefore, const FString& ChangeNote)
{
	ULocUGCSteamHelper::GetModContextForAPICall(ModId, [&](bool bSuccess, FModKitModDefinition* ModDefinition, UModKitEditorSettings* Settings, ISteamUGC* UGC)
	{
		if (!bSuccess)
		{
			return;
		}
		
		TFunction<void()> Upload = [&, ModDefinition, ModId, Settings, UGC, ChangeNote]
		{
			FString UploadDir = GetUploadDirForMod(ModId);

			UpdateManifest(ModDefinition->ModId);
			FString IconPath = ExportIcon(ModDefinition->ModId);

			auto UpdateHandle = UGC->StartItemUpdate(SteamUtils()->GetAppID(), ModDefinition->GetSteamPublisherFileId());
			UGC->SetItemContent(UpdateHandle, TCHAR_TO_ANSI(*UploadDir));
			if (!IconPath.IsEmpty())
			{
				UGC->SetItemPreview(UpdateHandle, TCHAR_TO_ANSI(*IconPath));
			}
			ULocUGCSteamHelper::SubmitItemUpdate(ModId, UpdateHandle, ChangeNote);
		};
		
		if (bBuildBefore)
		{
			BuildMod_Internal(*ModDefinition,[Upload](bool bSuccess)
			{
				if (bSuccess)
				{
					Upload();
				}
			});
		}
		else
		{
			Upload();	
		}
	});
}

FModKitModDefinition ULocModBuilderEditorWidget::GetModManifest(const FString& ModId)
{
	UModKitEditorSettings* ModKitSettings = GetMutableDefault<UModKitEditorSettings>();
	FModKitModDefinition Definition = *ModKitSettings->GetModDefinition(ModId);
	return Definition;
}

void ULocModBuilderEditorWidget::ShowModKitSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->ShowViewer("Project", "Editor", "ModKitEditorSettings");
	}
}

void ULocModBuilderEditorWidget::LaunchGame()
{
	const UModKitEditorSettings* ModKitSettings = GetDefault<UModKitEditorSettings>();
	FString LocExePath = FPaths::Combine(ModKitSettings->OddsparksSteamDirectory, "Oddsparks.exe");
	FString Params = "-ModsDir=\"" + FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectDir(), "Saved", "StagedMods", "Upload")) + "\" -EnableLoggingInShipping " + ModKitSettings->AdditionalLaunchArguments;
	FPlatformProcess::CreateProc(*LocExePath, *Params, true, true, true, nullptr, 0, nullptr, nullptr);
}

void ULocModBuilderEditorWidget::BuildMod_Internal(const FModKitModDefinition& ModDefinition, TFunction<void(bool)> OnComplete)
{
	const UModKitEditorSettings* ModKitSettings = GetDefault<UModKitEditorSettings>();
	
	int TargetChunk = ModDefinition.ChunkId;
	const FString ProjectPath = FPaths::ConvertRelativePathToFull(FPaths::SetExtension(FPaths::Combine(FPaths::ProjectDir(), FApp::GetProjectName()),".uproject"));
	FString ArchiveDirectory = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectDir(), "Saved", "StagedMods"));
	FString ModId = ModDefinition.ModId;

	FString TargetPakName = FString::Printf(TEXT("pakchunk%d-Windows"), TargetChunk);

	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	FString UploadDirectory = GetUploadDirForMod(ModId);
	FileManager.CreateDirectory(*UploadDirectory);	
	
	FString PathToPaks = FPaths::Combine(ArchiveDirectory, "Windows", "Loc", "Content", "Paks");
	TArray<FString> PakFiles = GetModFilesAt(PathToPaks);
	PakFiles.Append(GetModFilesAt(UploadDirectory));
	for (FString PakFile : PakFiles)
	{
		UE_LOG(LogTemp, Log, TEXT("Cleaning pak: %s"), *PakFile);
		FileManager.DeleteFile(*PakFile);
	}

	FString CommandLine = FString::Printf(TEXT("-ScriptsForProject=\"%s\" Turnkey -command=VerifySdk -platform=Win64 -UpdateIfNeeded -EditorIO -EditorIOPort=55083 -project=\"%s\" BuildCookRun -nop4 -utf8output -nocompileeditor -skipbuildeditor -cook  -project=\"%s\" -target=LocGame  -unrealexe=\"%s\" -platform=Win64 -stage -archive -package -build -pak -prereqs -archivedirectory=\"%s\" -manifests -clientconfig=Development -NoUba\"\""), *ProjectPath, *ProjectPath, *ProjectPath, *FUnrealEdMisc::Get().GetExecutableForCommandlets(), *ArchiveDirectory);
	IUATHelperModule::Get().CreateUatTask(CommandLine, FText::FromString("Windows"), FText::FromString("Packaging"), FText::FromString("Packaging"), nullptr, {},
		[&, TargetPakName, OnComplete, UploadDirectory, PathToPaks](FString ResultType, double Runtime)
	{
		AsyncTask(ENamedThreads::GameThread, [&, ResultType, TargetPakName, OnComplete, UploadDirectory, PathToPaks]()
		{
			UE_LOG(LogTemp, Log, TEXT("DONE PACKAGING %s"),*ResultType);

			if (ResultType != "Completed")
			{
				UE_LOG(LogTemp, Log, TEXT("Failed, aborting deploy"));
				OnComplete(false);
				return;
			}
		
			TArray<FString> NewPakFiles = GetModFilesAt(PathToPaks);
			for (FString PakFile : NewPakFiles)
			{
				UE_LOG(LogTemp, Log, TEXT("Found pak: %s"), *PakFile);
				FString PakName = FPaths::GetBaseFilename(PakFile);
				if (PakName == TargetPakName)
				{
					FString TargetUploadPath = FPaths::Combine(UploadDirectory, FPaths::GetCleanFilename(PakFile));
					FileManager.DeleteFile(*FPaths::SetExtension(TargetUploadPath, FPaths::GetExtension(PakFile)));
					FileManager.CopyFile(*TargetUploadPath, *PakFile);
				
					UE_LOG(LogTemp, Log, TEXT("[Mod deploy - AppData] copied %s to %s"), *PakFile, *TargetUploadPath);
				}
			}

			OnComplete(true);
		});
	});
}

TArray<FString> ULocModBuilderEditorWidget::GetAllowedSteamTags()
{
	return {"Workstation", "Logic", "Decoration", "Tool", "Cosmetic", "World Generation"};
}

void ULocModBuilderEditorWidget::UpdateItemTags(const FString& ModId, const TArray<FString>& Tags)
{
	ULocUGCSteamHelper::GetModContextForAPICall(ModId, [&, Tags](bool bSuccess, FModKitModDefinition* ModDefinition, UModKitEditorSettings* Settings, ISteamUGC* UGC)
	{
		if (!bSuccess)
		{
			return;
		}

		auto UpdateHandle = UGC->StartItemUpdate(SteamUtils()->GetAppID(), ModDefinition->GetSteamPublisherFileId());

		TArray<FTCHARToUTF8> Utf8Converters;
		Utf8Converters.Reserve(Tags.Num());

		TArray<const char*> Utf8Ptrs;
		Utf8Ptrs.Reserve(Tags.Num());

		for (const FString& Tag : Tags)
		{
			Utf8Converters.Emplace(*Tag);
			Utf8Ptrs.Add(Utf8Converters.Last().Get());
		}
		
		SteamParamStringArray_t SteamStringArray;
		SteamStringArray.m_nNumStrings = Utf8Ptrs.Num();
		SteamStringArray.m_ppStrings = Utf8Ptrs.GetData();
		
		UGC->SetItemTags(UpdateHandle, &SteamStringArray);
		ULocUGCSteamHelper::SubmitItemUpdate(ModId, UpdateHandle, "Updated Tags");
	});
}

UUserWidget* ULocModBuilderEditorWidget::OpenWidgetWithPopup(TSubclassOf<UUserWidget> PopupClass, const FString& Title, const FVector2D& Size)
{
	if (!PopupClass) return nullptr;

	UWorld* WidgetWorld = GEditor->GetEditorWorldContext().World();
	UUserWidget* PopupWidget = CreateWidget<UUserWidget>(WidgetWorld, PopupClass);
	if (!PopupWidget) return nullptr;

	TSharedRef<SWindow> Window = SNew(SWindow)
		.Title(FText::FromString(Title))
		.ClientSize(Size)
		.SupportsMinimize(true)
		.SupportsMaximize(true)
		.HasCloseButton(true)
		.IsPopupWindow(true)
		.IsTopmostWindow(true)
		[
			PopupWidget->TakeWidget()
		];

	FSlateApplication::Get().AddWindow(Window);
	return PopupWidget;
}

void ULocModBuilderEditorWidget::CloseWindowOfWidget(UUserWidget* Widget)
{
	TSharedPtr<SWindow> Window = FSlateApplication::Get().FindWidgetWindow(Widget->TakeWidget());
	if (Window.IsValid())
	{
		Window->RequestDestroyWindow();
	}
}