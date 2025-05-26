#pragma once
#include "CoreMinimal.h"
#include "SimulationManagerActorEventDelegate.generated.h"

class ASimulationActor;
class ASimulationManager;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSimulationManagerActorEvent, ASimulationManager*, SimulationManager, ASimulationActor*, SimulationActor);

