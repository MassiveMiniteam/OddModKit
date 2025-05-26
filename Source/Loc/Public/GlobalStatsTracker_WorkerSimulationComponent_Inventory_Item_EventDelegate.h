#pragma once
#include "CoreMinimal.h"
#include "ItemStack.h"
#include "GlobalStatsTracker_WorkerSimulationComponent_Inventory_Item_EventDelegate.generated.h"

class UInventoryComponent;
class UWorkerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FGlobalStatsTracker_WorkerSimulationComponent_Inventory_Item_Event, UWorkerSimulationComponent*, WorkerComponent, UInventoryComponent*, TargetInventory, FItemStack, ItemStack);

