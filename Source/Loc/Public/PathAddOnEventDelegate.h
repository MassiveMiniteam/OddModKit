#pragma once
#include "CoreMinimal.h"
#include "PathAddOnEventDelegate.generated.h"

class UPathAddOnSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPathAddOnEvent, UPathAddOnSimulationComponent*, AddOn);

