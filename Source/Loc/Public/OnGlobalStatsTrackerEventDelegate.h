#pragma once
#include "CoreMinimal.h"
#include "OnGlobalStatsTrackerEventDelegate.generated.h"

class UGlobalStatsTracker;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGlobalStatsTrackerEvent, UGlobalStatsTracker*, Tracker);

