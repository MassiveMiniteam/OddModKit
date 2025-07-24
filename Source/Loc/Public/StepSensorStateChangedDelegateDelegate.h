#pragma once
#include "CoreMinimal.h"
#include "StepSensorStateChangedDelegateDelegate.generated.h"

class UStepSensorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStepSensorStateChangedDelegate, UStepSensorSimulationComponent*, Component, bool, bIsPressedDown);

