#pragma once
#include "CoreMinimal.h"
#include "IncubatorEventDelegate.generated.h"

class UIncubatorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIncubatorEvent, UIncubatorSimulationComponent*, Incubator);

