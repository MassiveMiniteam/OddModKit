#pragma once
#include "CoreMinimal.h"
#include "GlobalStatsTracker_GridNetworkAgend_EventDelegate.generated.h"

class UGridNetworkAgentSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGlobalStatsTracker_GridNetworkAgend_Event, UGridNetworkAgentSimulationComponent*, Agent);

