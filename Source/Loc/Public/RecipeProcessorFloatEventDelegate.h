#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "RecipeProcessorFloatEventDelegate.generated.h"

class URecipeProcessorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRecipeProcessorFloatEvent, URecipeProcessorSimulationComponent*, Component, FFixed, Value);

