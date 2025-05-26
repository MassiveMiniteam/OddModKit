#pragma once
#include "CoreMinimal.h"
#include "SimulationPlayerEventDelegate.generated.h"

class ASimulationPlayer;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSimulationPlayerEvent, ASimulationPlayer*, SimulationPlayer);

