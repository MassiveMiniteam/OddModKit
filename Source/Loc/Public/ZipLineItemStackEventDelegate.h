#pragma once
#include "CoreMinimal.h"
#include "ItemStack.h"
#include "ZipLineItemStackEventDelegate.generated.h"

class UItemTransferActorPairSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FZipLineItemStackEvent, UItemTransferActorPairSimulationComponent*, Component, FItemStack, ItemStack);

