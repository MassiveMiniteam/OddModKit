#pragma once
#include "CoreMinimal.h"
#include "OnMinionControllerEventDelegate.generated.h"

class UMinionControllerSimulationBaseComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinionControllerEvent, UMinionControllerSimulationBaseComponent*, MinionControlComponent);

