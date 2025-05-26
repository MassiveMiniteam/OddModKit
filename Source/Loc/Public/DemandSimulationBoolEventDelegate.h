#pragma once
#include "CoreMinimal.h"
#include "DemandSimulationBoolEventDelegate.generated.h"

class UDemandSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDemandSimulationBoolEvent, UDemandSimulationComponent*, Component, bool, bState);

