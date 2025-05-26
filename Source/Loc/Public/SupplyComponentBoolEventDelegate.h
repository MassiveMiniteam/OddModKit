#pragma once
#include "CoreMinimal.h"
#include "SupplyComponentBoolEventDelegate.generated.h"

class USupplySimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSupplyComponentBoolEvent, USupplySimulationComponent*, Component, bool, bState);

