#pragma once
#include "CoreMinimal.h"
#include "MinionBuffComponent_DelegateDelegate.generated.h"

class UMinionBuffsSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMinionBuffComponent_Delegate, UMinionBuffsSimulationComponent*, Component);

