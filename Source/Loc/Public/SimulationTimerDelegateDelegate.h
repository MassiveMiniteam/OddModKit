#pragma once
#include "CoreMinimal.h"
#include "SimulationTimerDelegateDelegate.generated.h"

class USimulationTimerComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSimulationTimerDelegate, USimulationTimerComponent*, SimulationTimerComponent);

