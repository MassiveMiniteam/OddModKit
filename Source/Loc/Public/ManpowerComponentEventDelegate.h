#pragma once
#include "CoreMinimal.h"
#include "ManpowerComponentEventDelegate.generated.h"

class UManpowerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FManpowerComponentEvent, UManpowerSimulationComponent*, Component);

