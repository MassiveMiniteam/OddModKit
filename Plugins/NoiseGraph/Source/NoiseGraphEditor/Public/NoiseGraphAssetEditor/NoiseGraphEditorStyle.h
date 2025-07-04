#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"

class NOISEGRAPHEDITOR_API FNoiseGraphEditorStyle
{
public:
	static void Initialize();
	static void Shutdown();

	static const FName& GetStyleSetName();

private:
	static TSharedPtr<FSlateStyleSet> StyleSet;
};
