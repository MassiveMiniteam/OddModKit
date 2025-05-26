#include "NoiseGraphAssetEditor/EditorCommands_NoiseGraph.h"

#define LOCTEXT_NAMESPACE "EditorCommands_NoiseGraph"

void FEditorCommands_NoiseGraph::RegisterCommands()
{
	UI_COMMAND(GraphSettings, "Graph Settings", "Graph Settings", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(GeneratePreviews, "Generate Previews", "Generate Previews", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
