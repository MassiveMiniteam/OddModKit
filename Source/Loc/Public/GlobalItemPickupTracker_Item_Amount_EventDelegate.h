#pragma once
#include "CoreMinimal.h"
#include "GlobalItemPickupTracker_Item_Amount_EventDelegate.generated.h"

class UGlobalItemPickupTracker;
class UItemConfig;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FGlobalItemPickupTracker_Item_Amount_Event, UGlobalItemPickupTracker*, ItemPickupTracker, UItemConfig*, RecentlyPickedUpItem, int32, TotalAmount);

