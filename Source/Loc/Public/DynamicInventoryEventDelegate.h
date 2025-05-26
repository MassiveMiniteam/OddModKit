#pragma once
#include "CoreMinimal.h"
#include "DynamicInventoryEventDelegate.generated.h"

class UDynamicInventoryRefSimulation;
class UInventoryComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDynamicInventoryEvent, UDynamicInventoryRefSimulation*, DynamicInventory, UInventoryComponent*, NewInventory);

