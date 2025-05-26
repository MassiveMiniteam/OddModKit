#pragma once
#include "CoreMinimal.h"
#include "OnSensorCapacityUpdated_DelegateDelegate.generated.h"

class USensorCapacitySimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSensorCapacityUpdated_Delegate, USensorCapacitySimulationComponent*, Component);

