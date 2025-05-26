#pragma once
#include "CoreMinimal.h"
#include "BuildPreset.h"
#include "BuildToolPresetsPresentationEventDelegate.generated.h"

class UBuildPresetsPresentationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FBuildToolPresetsPresentationEvent, UBuildPresetsPresentationComponent*, Component, int32, Index, FBuildPreset, Preset);

