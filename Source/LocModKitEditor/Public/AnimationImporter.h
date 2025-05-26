// Copyright (C) Massive Miniteam GmbH 2020

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "StaticMeshAnimationContainer.h"
#include "AnimationImporter.generated.h"


class UAnimationContainer;
class UCurveVector;
class UStaticMeshAnimationContainer;
/**
 */
UCLASS()
class LOCMODKITEDITOR_API UAnimationImporter : public UEditorUtilityWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

	UFUNCTION(BlueprintCallable)
	void ImportStaticMeshAnimation(UAnimSequence* Animation, UAnimMontage* Montage, FString TrackName, UStaticMeshAnimationContainer* Container);
	
	UFUNCTION(BlueprintCallable)
	UAnimMontage* CreateAnimationMontage(UAnimSequence* AnimSequence);

	UFUNCTION(BlueprintCallable)
	FName GetFirstAndOnlyTrackName(UAnimSequence* AnimSequence);

private:
	void ImportAudioTrack(UAnimMontage* Montage, FString TrackName, UStaticMeshAnimationContainer* Container);
	
	UStaticMeshEffectTrack* CreateStaticMeshEffectTrackAsset(FString Name, FString TargetPath);

	UCurveVector* CreateCurveAsset(FString Name, FString TargetPath);

	UAnimMontage* CreateMontageFile(UAnimSequence* AnimSequence, FString SaveToFolderPath, FString FileName) const;

	void AddAngleFromRotKeyTryingToFixGimbalLock(FRichCurve& Curve, float Time, float PreviousAngle, float Angle);
	void ShowNotifyInfo(const FString& Message) const;
	void ShowEngineDialog(const FString& Message, const FString& OptTitle) const;
};
