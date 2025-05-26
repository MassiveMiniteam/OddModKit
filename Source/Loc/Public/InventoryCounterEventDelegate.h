#pragma once
#include "CoreMinimal.h"
#include "InventoryCounterEventDelegate.generated.h"

class UInventoryCounterSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryCounterEvent, UInventoryCounterSimulationComponent*, Component);

