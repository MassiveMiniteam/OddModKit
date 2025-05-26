#include "AssetTypeActions_NoiseGraph.h"
#include "NoiseGraphEditorPCH.h"
#include "NoiseGraphAssetEditor/AssetEditor_NoiseGraph.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions_NoiseGraph"

FAssetTypeActions_NoiseGraph::FAssetTypeActions_NoiseGraph(EAssetTypeCategories::Type InAssetCategory)
	: MyAssetCategory(InAssetCategory)
{
}

FText FAssetTypeActions_NoiseGraph::GetName() const
{
	return LOCTEXT("FNoiseGraphAssetTypeActionsName", "Noise Graph");
}

FColor FAssetTypeActions_NoiseGraph::GetTypeColor() const
{
	return FColor(129, 196, 115);
}

UClass* FAssetTypeActions_NoiseGraph::GetSupportedClass() const
{
	return UNoiseGraph::StaticClass();
}

void FAssetTypeActions_NoiseGraph::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		if (UNoiseGraph* Graph = Cast<UNoiseGraph>(*ObjIt))
		{
			TSharedRef<FAssetEditor_NoiseGraph> NewGraphEditor(new FAssetEditor_NoiseGraph());
			NewGraphEditor->InitNoiseGraphAssetEditor(Mode, EditWithinLevelEditor, Graph);
		}
	}
}

uint32 FAssetTypeActions_NoiseGraph::GetCategories()
{
	return MyAssetCategory;
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE