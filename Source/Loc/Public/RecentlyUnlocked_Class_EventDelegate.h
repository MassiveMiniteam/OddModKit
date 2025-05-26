#pragma once
#include "CoreMinimal.h"
#include "RecentlyUnlocked_Class_EventDelegate.generated.h"

class URecentlyUnlockedAssetsTracker;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRecentlyUnlocked_Class_Event, URecentlyUnlockedAssetsTracker*, RecentlyUnlockedTracker, UClass*, UnlockedClass);

