#include "NoiseGraphAssetEditor/AssetEditorToolbar_NoiseGraph.h"
#include "NoiseGraphAssetEditor/AssetEditor_NoiseGraph.h"
#include "NoiseGraphAssetEditor/EditorCommands_NoiseGraph.h"
#include "NoiseGraphAssetEditor/NoiseGraphEditorStyle.h"

#define LOCTEXT_NAMESPACE "AssetEditorToolbar_NoiseGraph"

void FAssetEditorToolbar_NoiseGraph::AddNoiseGraphToolbar(TSharedPtr<FExtender> Extender)
{
	check(NoiseGraphEditor.IsValid());
	TSharedPtr<FAssetEditor_NoiseGraph> NoiseGraphEditorPtr = NoiseGraphEditor.Pin();

	TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
	ToolbarExtender->AddToolBarExtension("Asset", EExtensionHook::After, NoiseGraphEditorPtr->GetToolkitCommands(), FToolBarExtensionDelegate::CreateSP( this, &FAssetEditorToolbar_NoiseGraph::FillNoiseGraphToolbar ));
	NoiseGraphEditorPtr->AddToolbarExtender(ToolbarExtender);
}

void FAssetEditorToolbar_NoiseGraph::FillNoiseGraphToolbar(FToolBarBuilder& ToolbarBuilder)
{
	check(NoiseGraphEditor.IsValid());
	TSharedPtr<FAssetEditor_NoiseGraph> NoiseGraphEditorPtr = NoiseGraphEditor.Pin();

	ToolbarBuilder.BeginSection("Noise Graph");
	{
		ToolbarBuilder.AddToolBarButton(FEditorCommands_NoiseGraph::Get().GraphSettings,
			NAME_None,
			LOCTEXT("GraphSettings_Label", "Graph Settings"),
			LOCTEXT("GraphSettings_ToolTip", "Show the Graph Settings"),
			FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.GameSettings"));
	}
	ToolbarBuilder.EndSection();

	ToolbarBuilder.BeginSection("Util");
	{
		ToolbarBuilder.AddToolBarButton(FEditorCommands_NoiseGraph::Get().GeneratePreviews,
			NAME_None,
			LOCTEXT("GeneratePreviews_Label", "Generate Previews"),
			LOCTEXT("GeneratePreviews_ToolTip", "Generate Previews"),
			FSlateIcon(FAppStyle::GetAppStyleSetName(), "NoiseGraphEditor.GeneratePreviews"));
	}
	ToolbarBuilder.EndSection();

}


#undef LOCTEXT_NAMESPACE
