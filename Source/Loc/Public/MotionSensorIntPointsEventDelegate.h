#pragma once
#include "CoreMinimal.h"
#include "MotionSensorIntPointsEventDelegate.generated.h"

class ASimulationActor;
class UMotionSensorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMotionSensorIntPointsEvent, UMotionSensorSimulationComponent*, MotionSensorSimulationComponent, const TArray<ASimulationActor*>&, DetectedActors);

