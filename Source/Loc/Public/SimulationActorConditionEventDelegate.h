#pragma once
#include "CoreMinimal.h"
#include "SimulationActorConditionEventDelegate.generated.h"

class ASimulationActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(bool, FSimulationActorConditionEvent, ASimulationActor*, SimulationActor);

