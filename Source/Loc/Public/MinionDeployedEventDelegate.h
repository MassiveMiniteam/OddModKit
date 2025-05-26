#pragma once
#include "CoreMinimal.h"
#include "MinionDeployedEventDelegate.generated.h"

class ASimulationActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMinionDeployedEvent, ASimulationActor*, Minion);

