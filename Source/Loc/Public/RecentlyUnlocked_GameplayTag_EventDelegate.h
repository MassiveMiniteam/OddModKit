#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "RecentlyUnlocked_GameplayTag_EventDelegate.generated.h"

class URecentlyUnlockedAssetsTracker;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRecentlyUnlocked_GameplayTag_Event, URecentlyUnlockedAssetsTracker*, RecentlyUnlockedTracker, FGameplayTag, GameplayTag);

