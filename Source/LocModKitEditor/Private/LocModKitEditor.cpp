#include "LocModKitEditor.h"

#include "AssetToolsModule.h"
#include "ContentBrowserModule.h"
#include "Fixed64Customization.h"
#include "FixedCustomization.h"
#include "IAssetTools.h"
#include "LevelEditor.h"
#include "LocAssetDumpImporter.h"
#include "AssetRegistry/AssetRegistryModule.h"

#define LOCTEXT_NAMESPACE "FLocModKitEditorModule"

static FAutoConsoleCommand ImportAssetDumpCommand(
	TEXT("LocEditor.ImportAssetDump"),
	TEXT("Imports asset dump"),
	FConsoleCommandWithArgsDelegate::CreateLambda([](const TArray<FString>& Args)
	{
		ULocAssetDumpImporter::ImportAssetDump(Args[0], {});
	}),
	ECVF_Default
	);

static FAutoConsoleCommand TestDependenciesCommand(
	TEXT("LocEditor.TestDependencies"),
	TEXT("lists dummy dependencies"),
	FConsoleCommandWithArgsDelegate::CreateLambda([](const TArray<FString>& Args)
	{
		ULocAssetDumpImporter::TestDependencies(Args[0], Args[1]);
	}),
	ECVF_Default
);

static FAutoConsoleCommand ListAssetMetaData(
	TEXT("LocEditor.ListAssetMetaData"),
	TEXT("Lists asset meta data"),
	FConsoleCommandWithArgsDelegate::CreateLambda([](const TArray<FString>& Args)
	{
		ULocAssetDumpImporter::ListAssetMetaData();
	}),
	ECVF_Default
);

void FLocModKitEditorModule::StartupModule()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.RegisterCustomPropertyTypeLayout("Fixed", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FFixedCustomization::MakeInstance));
	PropertyModule.RegisterCustomPropertyTypeLayout("Fixed64", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FFixed64Customization::MakeInstance));
	PropertyModule.NotifyCustomizationModuleChanged();
	
	AddCustomContextMenuExtender();

	SetupToolMenu();
}

void FLocModKitEditorModule::ShutdownModule()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.UnregisterCustomPropertyTypeLayout("Fixed");
	PropertyModule.NotifyCustomizationModuleChanged();
}

void FLocModKitEditorModule::AddCustomContextMenuExtender()
{
	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");

	TSharedRef<FExtender> Extender = MakeShared<FExtender>();
	ContentBrowserModule.GetAllAssetViewContextMenuExtenders().Add(FContentBrowserMenuExtender_SelectedAssets::CreateStatic(&FLocModKitEditorModule::ExtendAssetContextMenu));
}

TSharedRef<FExtender> FLocModKitEditorModule::ExtendAssetContextMenu(const TArray<FAssetData>& AssetList)
{
	TSharedRef<FExtender> Extender = MakeShared<FExtender>();

	Extender->AddMenuExtension(
		"CommonAssetActions",
		EExtensionHook::After,
		nullptr,
		FMenuExtensionDelegate::CreateStatic(&FLocModKitEditorModule::CreateCustomMenuEntry, AssetList)
	);

	return Extender;
}

void FLocModKitEditorModule::CreateCustomMenuEntry(FMenuBuilder& MenuBuilder, TArray<FAssetData> SelectedAssets)
{
	bool bHasDummyAsset = false;
	for (auto Item : SelectedAssets)
	{
		if (Item.PackagePath.ToString().StartsWith("/Game/LOC"))
		{
			bHasDummyAsset = true;
			break;
		}
	}

	if (bHasDummyAsset)
	{
		MenuBuilder.AddMenuEntry(
			FText::FromString("Recreate Dummy Asset"),
			FText::FromString("Recreates the dummy assets"),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateStatic(&FLocModKitEditorModule::ExecuteCustomAction_RecreateDummyAssets, SelectedAssets))
		);
	}
	else
	{
		MenuBuilder.AddMenuEntry(
			FText::FromString("Fixup Dummy References"),
			FText::FromString("Gets referenced dummy assets assets and restores them"),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateStatic(&FLocModKitEditorModule::ExecuteCustomAction_FixupDummyReferences, SelectedAssets))
		);
	}
}

void FLocModKitEditorModule::ExecuteCustomAction_RecreateDummyAssets(TArray<FAssetData> SelectedAssets)
{
	ULocAssetDumpImporter::ImportAssetDump(FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectDir(), "AssetDump.bin")), SelectedAssets);
}

void FLocModKitEditorModule::ExecuteCustomAction_FixupDummyReferences(TArray<FAssetData> SelectedAssets)
{
	for (auto File : SelectedAssets)
	{
		FString AssetList = "";
		TArray<FString> AssetReferences;
		GetAssetReferences(File.PackagePath.ToString() + "/" + File.AssetName.ToString(), AssetReferences);
		for (FString Ref : AssetReferences)
		{
			if (Ref.StartsWith("/Game/LOC"))
			{
				UE_LOG(LogTemp, Log, TEXT("%s"), *Ref);
				AssetList += Ref + "\n";
			}
		}

		auto Result = FMessageDialog::Open(EAppMsgCategory::Info, EAppMsgType::OkCancel, FText::FromString(FString::Printf(TEXT("These dependencies will be fixed. This will quit the editor:\n\n\n%s"), *AssetList)));
		if (Result == EAppReturnType::Ok)
		{
			FString ToReimportPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir() / "ToReimport.txt");
			FFileHelper::SaveStringToFile(AssetList, *ToReimportPath);

			FString Command = TEXT("cmd.exe");
			FString Bat = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir() / "../Tools/RecreateDummiesFromFile.bat");
			FString Arguments = FString::Printf(TEXT("/C start \"\" \"%s\" %s"), *Bat, *ToReimportPath);

			// Optional: Set working directory
			FString WorkingDirectory = FPaths::ProjectDir() / "Tools";

			// Create the new process (don't wait for it, don't kill tree on exit)
			FProcHandle ProcHandle = FPlatformProcess::CreateProc(
				*Command,
				*Arguments,
				true,   // bLaunchDetached
				false,  // bLaunchHidden
				false,  // bLaunchReallyHidden
				nullptr,
				0,
				*WorkingDirectory,
				nullptr
			);

			if (ProcHandle.IsValid())
			{
				FTimerHandle TimerHandle;
				GEditor->GetTimerManager()->SetTimer(TimerHandle, []()
				{
					FGenericPlatformMisc::RequestExit(false);
				}, 1.0f, false);  // 1-second delay before quitting
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed to start the process."));
			}
		}
	}
}

void FLocModKitEditorModule::GetAssetReferences(const FString& AssetPath, TArray<FString>& References)
{
	// Load the Asset Registry Module
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

	TArray<FName> DependencyNames;
	if (AssetRegistry.GetDependencies(FName(AssetPath), DependencyNames))
	{
		TArray<FString> NewReferences;
		for (const FName& DepName : DependencyNames)
		{
			if (!References.Contains(DepName.ToString()))
			{
				NewReferences.Add(DepName.ToString());
				References.Add(DepName.ToString());
			}
		}

		for (FString NewRef : NewReferences)
		{
			GetAssetReferences(NewRef, References);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get dependencies for %s"), *AssetPath);
	}
}

void FLocModKitEditorModule::OpenAssetDumpImporter()
{
	ULocAssetDumpImporter::ImportAssetDump(FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectDir(), "AssetDump.bin")), {});
}

void FLocModKitEditorModule::SetupToolMenu()
{
	FLocModKitEditorCommands::Register();
	LocCustomCommands = MakeShareable(new FUICommandList);
	LocCustomCommands->MapAction(
		FLocModKitEditorCommands::Get().OpenAssetDumpImporter,
		FExecuteAction::CreateRaw(this, &FLocModKitEditorModule::OpenAssetDumpImporter),
		FCanExecuteAction());
	
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu");
	auto SubMenu = Menu->AddSubMenu("MainMenu", NAME_None, "Loc", LOCTEXT("LocMenu", "OddModKit"), LOCTEXT("LocMenu_ToolTip", "Custom Actions for OddModKit"));
	auto section = SubMenu->AddSection("LocMenuRoot");

	TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
	MenuExtender->AddMenuExtension("LocMenuRoot", EExtensionHook::After, LocCustomCommands, FMenuExtensionDelegate::CreateRaw(this, &FLocModKitEditorModule::AddMenuExtension));
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
}

void FLocModKitEditorModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.BeginSection("LocAssetDumpImporter", LOCTEXT("AssetDumpImporter", "Asset Dump Importer"));
	Builder.AddMenuEntry(FLocModKitEditorCommands::Get().OpenAssetDumpImporter);
	Builder.EndSection();
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FLocModKitEditorModule, LocModKitEditor)