#pragma once
#include "CoreMinimal.h"
#include "TemperatureReceiverDelegateDelegate.generated.h"

class UTemperatureReceiverSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTemperatureReceiverDelegate, UTemperatureReceiverSimulationComponent*, Component);

