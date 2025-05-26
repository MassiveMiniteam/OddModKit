#pragma once
#include "CoreMinimal.h"
#include "InventorySlotDeletedEventDelegate.generated.h"

class UInventoryComponent;
class UItemConfig;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FInventorySlotDeletedEvent, UInventoryComponent*, Inventory, UItemConfig*, ItemConfig, int32, Amount, int32, Slot);

