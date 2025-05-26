#pragma once
#include "CoreMinimal.h"
#include "RecipeChangedEventDelegate.generated.h"

class URecipeConfig;
class URecipeProcessorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRecipeChangedEvent, URecipeProcessorSimulationComponent*, Component, URecipeConfig*, Recipe);

