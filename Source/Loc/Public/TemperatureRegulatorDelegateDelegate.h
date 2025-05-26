#pragma once
#include "CoreMinimal.h"
#include "TemperatureRegulatorDelegateDelegate.generated.h"

class UTemperatureRegulatorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTemperatureRegulatorDelegate, UTemperatureRegulatorSimulationComponent*, Component);

