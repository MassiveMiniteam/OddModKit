#pragma once
#include "CoreMinimal.h"
#include "SimulationCommandRunEventDelegate.generated.h"

class USimulationCommand;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSimulationCommandRunEvent, USimulationCommand*, SimulationCommand);

