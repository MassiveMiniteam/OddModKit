#pragma once
#include "CoreMinimal.h"
#include "ItemDecayInventoryEventDelegate.generated.h"

class UInventoryComponent;
class UItemDecayComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FItemDecayInventoryEvent, UItemDecayComponent*, Component, UInventoryComponent*, Inventory);

