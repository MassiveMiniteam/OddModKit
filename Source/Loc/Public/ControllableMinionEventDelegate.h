#pragma once
#include "CoreMinimal.h"
#include "ControllableMinionEventDelegate.generated.h"

class UMinionControllerSimulationBaseComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FControllableMinionEvent, UMinionControllerSimulationBaseComponent*, MinionController);

