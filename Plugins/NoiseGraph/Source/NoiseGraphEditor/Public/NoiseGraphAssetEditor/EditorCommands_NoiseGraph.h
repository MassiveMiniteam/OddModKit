#pragma once

#include "CoreMinimal.h"
#include "EditorStyleSet.h"

class NOISEGRAPHEDITOR_API FEditorCommands_NoiseGraph : public TCommands<FEditorCommands_NoiseGraph>
{
public:
	/** Constructor */
	FEditorCommands_NoiseGraph()
		: TCommands<FEditorCommands_NoiseGraph>("NoiseGraphEditor", NSLOCTEXT("Contexts", "NoiseGraphEditor", "Noise Graph Editor"), NAME_None, FAppStyle::GetAppStyleSetName())
	{
	}
	
	TSharedPtr<FUICommandInfo> GraphSettings;
	TSharedPtr<FUICommandInfo> GeneratePreviews;

	virtual void RegisterCommands() override;
};
