#pragma once
#include "CoreMinimal.h"
#include "CounterGateEventDelegate.generated.h"

class ULogicCounterGateSimulation;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCounterGateEvent, ULogicCounterGateSimulation*, Gate);

