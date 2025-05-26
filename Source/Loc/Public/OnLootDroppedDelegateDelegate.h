#pragma once
#include "CoreMinimal.h"
#include "ItemStack.h"
#include "OnLootDroppedDelegateDelegate.generated.h"

class ULootDropSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLootDroppedDelegate, ULootDropSimulationComponent*, LootDropSimulationComponent, FItemStack, ItemStack);

