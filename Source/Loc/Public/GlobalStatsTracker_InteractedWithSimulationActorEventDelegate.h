#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GlobalStatsTracker_InteractedWithSimulationActorEventDelegate.generated.h"

class ASimulationActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGlobalStatsTracker_InteractedWithSimulationActorEvent, TSubclassOf<ASimulationActor>, SimulationActorType);

