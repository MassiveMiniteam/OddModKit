#pragma once
#include "CoreMinimal.h"
#include "LogicClockEventDelegate.generated.h"

class ULogicClockSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLogicClockEvent, ULogicClockSimulationComponent*, Component);

