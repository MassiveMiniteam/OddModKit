#pragma once
#include "CoreMinimal.h"
#include "RecentlyUnlockedDataAssetEventDelegate.generated.h"

class UDataAsset;
class URecentlyUnlockedAssetsTrackerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRecentlyUnlockedDataAssetEvent, URecentlyUnlockedAssetsTrackerSimulationComponent*, Component, UDataAsset*, DataAsset);

