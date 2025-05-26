#pragma once
#include "CoreMinimal.h"
#include "TimedOverlapEventDelegate.generated.h"

class UTimedOverlapActionSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTimedOverlapEvent, UTimedOverlapActionSimulationComponent*, Component);

