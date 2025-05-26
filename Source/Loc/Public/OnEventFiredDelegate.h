#pragma once
#include "CoreMinimal.h"
#include "OnEventFiredDelegate.generated.h"

class USimulationTimerComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventFired, USimulationTimerComponent*, SimulationTimerComponent);

