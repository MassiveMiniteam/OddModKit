#pragma once
#include "CoreMinimal.h"
#include "BuildPreset.h"
#include "BuildPresetSelectionChangedEventDelegate.generated.h"

class UBuildPresetsSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FBuildPresetSelectionChangedEvent, UBuildPresetsSimulationComponent*, Component, int32, Index, FBuildPreset, Preset, bool, bUpdatePresentation);

