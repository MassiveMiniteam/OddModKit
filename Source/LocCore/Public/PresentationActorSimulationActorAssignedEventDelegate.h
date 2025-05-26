#pragma once
#include "CoreMinimal.h"
#include "PresentationActorSimulationActorAssignedEventDelegate.generated.h"

class APresentationActor;
class ASimulationActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPresentationActorSimulationActorAssignedEvent, APresentationActor*, Actor, ASimulationActor*, SimulationActor);

