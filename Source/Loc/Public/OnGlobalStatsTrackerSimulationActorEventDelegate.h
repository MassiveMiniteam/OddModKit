#pragma once
#include "CoreMinimal.h"
#include "OnGlobalStatsTrackerSimulationActorEventDelegate.generated.h"

class ASimulationActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGlobalStatsTrackerSimulationActorEvent, ASimulationActor*, SimulationActor);

