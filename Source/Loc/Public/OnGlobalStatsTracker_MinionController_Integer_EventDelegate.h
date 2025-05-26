#pragma once
#include "CoreMinimal.h"
#include "OnGlobalStatsTracker_MinionController_Integer_EventDelegate.generated.h"

class UMinionControllerSimulationBaseComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGlobalStatsTracker_MinionController_Integer_Event, UMinionControllerSimulationBaseComponent*, MinionController, int32, Value);

