#include "NoiseGraphEditor.h"
#include "NoiseGraphNodeFactory.h"
#include "AssetTypeActions_NoiseGraph.h"
#include "NoiseGraphAssetEditor/NoiseGraphEditorStyle.h"

DEFINE_LOG_CATEGORY(NoiseGraphEditor)

#define LOCTEXT_NAMESPACE "Editor_NoiseGraph"

IMPLEMENT_MODULE(FNoiseGraphEditor, NoiseGraphEditor)

void FNoiseGraphEditor::StartupModule()
{
	FNoiseGraphEditorStyle::Initialize();

	GraphPanelNodeFactory_NoiseGraph = MakeShareable(new FGraphPanelNodeFactory_NoiseGraph());
	FEdGraphUtilities::RegisterVisualNodeFactory(GraphPanelNodeFactory_NoiseGraph);

	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	NoiseGraphAssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("NoiseGraph")), LOCTEXT("NoiseGraphAssetCategory", "NoiseGraph"));

	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_NoiseGraph(NoiseGraphAssetCategoryBit)));
}


void FNoiseGraphEditor::ShutdownModule()
{
	// Unregister all the asset types that we registered
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for (int32 Index = 0; Index < CreatedAssetTypeActions.Num(); ++Index)
		{
			AssetTools.UnregisterAssetTypeActions(CreatedAssetTypeActions[Index].ToSharedRef());
		}
	}

	if (GraphPanelNodeFactory_NoiseGraph.IsValid())
	{
		FEdGraphUtilities::UnregisterVisualNodeFactory(GraphPanelNodeFactory_NoiseGraph);
		GraphPanelNodeFactory_NoiseGraph.Reset();
	}

	FNoiseGraphEditorStyle::Shutdown();
}

void FNoiseGraphEditor::RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}

#undef LOCTEXT_NAMESPACE

