#pragma once
#include "CoreMinimal.h"
#include "ItemStack.h"
#include "ItemSlotChangedEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemSlotChangedEvent, FItemStack, Item);

