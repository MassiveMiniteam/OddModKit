
#pragma once

#include "CoreMinimal.h"

class FAssetEditor_NoiseGraph;
class FExtender;
class FToolBarBuilder;

class NOISEGRAPHEDITOR_API FAssetEditorToolbar_NoiseGraph : public TSharedFromThis<FAssetEditorToolbar_NoiseGraph>
{
public:
	FAssetEditorToolbar_NoiseGraph(TSharedPtr<FAssetEditor_NoiseGraph> InNoiseGraphEditor)
		: NoiseGraphEditor(InNoiseGraphEditor) {}

	void AddNoiseGraphToolbar(TSharedPtr<FExtender> Extender);

private:
	void FillNoiseGraphToolbar(FToolBarBuilder& ToolbarBuilder);

protected:
	/** Pointer back to the blueprint editor tool that owns us */
	TWeakPtr<FAssetEditor_NoiseGraph> NoiseGraphEditor;
};
