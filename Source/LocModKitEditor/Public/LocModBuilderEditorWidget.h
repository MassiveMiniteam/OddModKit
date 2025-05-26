// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "LocModBuilderEditorWidget.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class LOCMODKITEDITOR_API ULocModBuilderEditorWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	
	UFUNCTION(BlueprintCallable)
	void BuildMod(const FModKitModDefinition& ModDefinition);
	
	UFUNCTION(BlueprintCallable)
	void UploadModToSteam(const FString& ModId, bool bBuildBefore, const FString& ChangeNote);

	UFUNCTION(BlueprintCallable)
	FModKitModDefinition GetModManifest(const FString& ModId);

	UFUNCTION(BlueprintCallable)
	void ShowModKitSettings();
	UFUNCTION(BlueprintCallable)
	void LaunchGame();

	UFUNCTION(BlueprintCallable)
	TArray<FString> GetAllowedSteamTags();
	UFUNCTION(BlueprintCallable)
	void UpdateItemTags(const FString& ModId, const TArray<FString>& Tags);
	UFUNCTION(BlueprintCallable)
	UUserWidget* OpenWidgetWithPopup(TSubclassOf<UUserWidget> PopupClass, const FString& Title, const FVector2D& Size);
	UFUNCTION(BlueprintCallable)
	void CloseWindowOfWidget(UUserWidget* Widget);

	void BuildMod_Internal(const FModKitModDefinition& ModDefinition, TFunction<void(bool)> OnComplete);
	TArray<FString> GetModFilesAt(const FString& Path);
	FString GetUploadDirForMod(const FString& ModId);
	void UpdateManifest(const FString& ModId);
	FString ExportIcon(const FString& ModId);
};
