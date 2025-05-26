#pragma once
#include "CoreMinimal.h"
#include "InventoryChangeEventDelegate.generated.h"

class UInventoryComponent;
class UItemConfig;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FInventoryChangeEvent, UInventoryComponent*, Inventory, bool, bAdded, UItemConfig*, Item);

