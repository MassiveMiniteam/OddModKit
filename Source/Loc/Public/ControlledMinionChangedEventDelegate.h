#pragma once
#include "CoreMinimal.h"
#include "ControlledMinionChangedEventDelegate.generated.h"

class ASimulationActor;
class UMinionControllerSimulationBaseComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FControlledMinionChangedEvent, UMinionControllerSimulationBaseComponent*, MinionControlComponent, ASimulationActor*, Minion);

