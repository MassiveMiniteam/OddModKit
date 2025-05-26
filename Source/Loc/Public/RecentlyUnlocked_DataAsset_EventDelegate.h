#pragma once
#include "CoreMinimal.h"
#include "RecentlyUnlocked_DataAsset_EventDelegate.generated.h"

class UDataAsset;
class URecentlyUnlockedAssetsTracker;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRecentlyUnlocked_DataAsset_Event, URecentlyUnlockedAssetsTracker*, RecentlyUnlockedTracker, UDataAsset*, DataAsset);

