#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "IncubatorProgressEventDelegate.generated.h"

class UIncubatorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIncubatorProgressEvent, UIncubatorSimulationComponent*, Incubator, FFixed, Progress);

