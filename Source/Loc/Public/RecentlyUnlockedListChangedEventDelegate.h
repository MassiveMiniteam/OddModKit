#pragma once
#include "CoreMinimal.h"
#include "RecentlyUnlockedListChangedEventDelegate.generated.h"

class URecentlyUnlockedAssetsTrackerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRecentlyUnlockedListChangedEvent, URecentlyUnlockedAssetsTrackerSimulationComponent*, Component);

