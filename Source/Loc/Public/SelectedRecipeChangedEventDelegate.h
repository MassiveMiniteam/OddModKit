#pragma once
#include "CoreMinimal.h"
#include "SelectedRecipeChangedEventDelegate.generated.h"

class URecipeConfig;
class USelectableRecipesSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSelectedRecipeChangedEvent, USelectableRecipesSimulationComponent*, Component, URecipeConfig*, Recipe);

