#pragma once

#include "CoreMinimal.h"
#include "ContentBrowserDelegates.h"
#include "Modules/ModuleManager.h"

class FLocModKitEditorModule : public IModuleInterface
{
public:
	
	TSharedPtr<class FUICommandList> LocCustomCommands;

    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
	void OpenAssetDumpImporter();
    void SetupToolMenu();

	void AddCustomContextMenuExtender();

	static TSharedRef<FExtender> ExtendAssetContextMenu(const TArray<FAssetData>& AssetList);
	static void CreateCustomMenuEntry(FMenuBuilder& MenuBuilder, TArray<FAssetData> SelectedAssets);
	static void ExecuteCustomAction_RecreateDummyAssets(TArray<FAssetData> SelectedAssets);
	static void ExecuteCustomAction_FixupDummyReferences(TArray<FAssetData> SelectedAssets);
	static void GetAssetReferences(const FString& AssetPath, TArray<FString>& References);
	
    void AddMenuExtension(FMenuBuilder& Builder);
};

#define LOCTEXT_NAMESPACE "FLocModKitEditorModule"
class FLocModKitEditorCommands : public TCommands<FLocModKitEditorCommands>
{
public:
	FLocModKitEditorCommands() : TCommands<FLocModKitEditorCommands>(TEXT("LocModKitEditor"), NSLOCTEXT("Contexts", "LocModKitEditor", "LocModKitEditor Plugin"), NAME_None, GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override
	{
		UI_COMMAND(OpenAssetDumpImporter, "Open Asset Dump Importer", "", EUserInterfaceActionType::Button, FInputGesture());
	}

	static FName GetStyleSetName()
	{
		static FName StyleSetName(TEXT("LocCustomEditorStyle"));
		return StyleSetName;
	}

public:
	TSharedPtr<FUICommandInfo> OpenAssetDumpImporter;
};

#undef LOCTEXT_NAMESPACE