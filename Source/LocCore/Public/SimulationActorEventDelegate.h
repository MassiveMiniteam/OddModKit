#pragma once
#include "CoreMinimal.h"
#include "EDestructionReason.h"
#include "SimulationActorEventDelegate.generated.h"

class ASimulationActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSimulationActorEvent, ASimulationActor*, SimulationActor, EDestructionReason, Reason);

