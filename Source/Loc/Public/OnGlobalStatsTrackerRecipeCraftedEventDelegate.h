#pragma once
#include "CoreMinimal.h"
#include "OnGlobalStatsTrackerRecipeCraftedEventDelegate.generated.h"

class URecipeConfig;
class URecipeProcessorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGlobalStatsTrackerRecipeCraftedEvent, URecipeProcessorSimulationComponent*, Component, URecipeConfig*, Recipe);

