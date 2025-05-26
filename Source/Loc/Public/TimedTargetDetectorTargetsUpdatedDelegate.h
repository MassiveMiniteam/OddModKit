#pragma once
#include "CoreMinimal.h"
#include "TimedTargetDetectorTargetsUpdatedDelegate.generated.h"

class ASimulationActor;
class UTimedTargetDetectorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTimedTargetDetectorTargetsUpdated, UTimedTargetDetectorSimulationComponent*, Component, ASimulationActor*, TargetActor, ASimulationActor*, ClosestHighPrioTarget);

