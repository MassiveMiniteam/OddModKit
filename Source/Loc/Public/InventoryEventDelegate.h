#pragma once
#include "CoreMinimal.h"
#include "InventoryEventDelegate.generated.h"

class UInventoryComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryEvent, UInventoryComponent*, Inventory);

