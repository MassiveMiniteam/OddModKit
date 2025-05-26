#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "OnGlobalStatsTrackerRecipeProgressEventDelegate.generated.h"

class URecipeProcessorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGlobalStatsTrackerRecipeProgressEvent, URecipeProcessorSimulationComponent*, Component, FFixed, Progress);

