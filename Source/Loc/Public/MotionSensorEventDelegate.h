#pragma once
#include "CoreMinimal.h"
#include "MotionSensorEventDelegate.generated.h"

class UMotionSensorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMotionSensorEvent, UMotionSensorSimulationComponent*, MotionSensorSimulationComponent);

