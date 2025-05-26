#pragma once
#include "CoreMinimal.h"
#include "OnGlobalStatsTrackerWorkerMinionAssignedDelegate.generated.h"

class UManpowerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGlobalStatsTrackerWorkerMinionAssigned, UManpowerSimulationComponent*, Component);

