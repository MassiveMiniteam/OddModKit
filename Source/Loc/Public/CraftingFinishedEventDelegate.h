#pragma once
#include "CoreMinimal.h"
#include "CraftingFinishedEventDelegate.generated.h"

class URecipeConfig;
class URecipeProcessorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCraftingFinishedEvent, URecipeProcessorSimulationComponent*, Component, URecipeConfig*, Recipe);

