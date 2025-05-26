#pragma once
#include "CoreMinimal.h"
#include "TemperatureEmitterChangedEventDelegate.generated.h"

class UTemperatureEmitterSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTemperatureEmitterChangedEvent, UTemperatureEmitterSimulationComponent*, Component, int32, Temperature);

