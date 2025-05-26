#pragma once
#include "CoreMinimal.h"
#include "BuildToolPresetsRowSelectPresentationEventDelegate.generated.h"

class UBuildPresetsPresentationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBuildToolPresetsRowSelectPresentationEvent, UBuildPresetsPresentationComponent*, Component, int32, NewRowIndex);

