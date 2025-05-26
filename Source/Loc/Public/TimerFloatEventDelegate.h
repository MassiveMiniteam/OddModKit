#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "TimerFloatEventDelegate.generated.h"

class USimulationTimerComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTimerFloatEvent, USimulationTimerComponent*, SimulationTimerComponent, FFixed, Value);

