#pragma once
#include "CoreMinimal.h"
#include "ItemStack.h"
#include "LootDropTracker_LootDrop_EventDelegate.generated.h"

class ULootDropSimulationComponent;
class ULootDropTrackerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FLootDropTracker_LootDrop_Event, ULootDropTrackerSimulationComponent*, LootDropTrackerComponent, FItemStack, DroppedItemStack, ULootDropSimulationComponent*, LootDropComponent);

