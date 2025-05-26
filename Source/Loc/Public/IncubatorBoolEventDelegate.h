#pragma once
#include "CoreMinimal.h"
#include "IncubatorBoolEventDelegate.generated.h"

class UIncubatorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIncubatorBoolEvent, UIncubatorSimulationComponent*, Incubator, bool, bValue);

