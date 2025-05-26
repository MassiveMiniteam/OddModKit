#pragma once
#include "CoreMinimal.h"
#include "RecentlyUnlocked_EventDelegate.generated.h"

class URecentlyUnlockedAssetsTracker;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRecentlyUnlocked_Event, URecentlyUnlockedAssetsTracker*, RecentlyUnlockedTracker);

