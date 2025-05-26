#pragma once
#include "CoreMinimal.h"
#include "ItemStack.h"
#include "ItemTransferComponentDelegateDelegate.generated.h"

class UItemTransferSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FItemTransferComponentDelegate, UItemTransferSimulationComponent*, Component, FItemStack, ItemStack);

