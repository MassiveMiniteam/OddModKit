#pragma once
#include "CoreMinimal.h"
#include "OnSimulationTickEventDelegate.generated.h"

class ASimulationManager;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSimulationTickEvent, ASimulationManager*, SimulationManager);

