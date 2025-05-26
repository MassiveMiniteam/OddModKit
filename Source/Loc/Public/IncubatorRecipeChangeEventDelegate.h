#pragma once
#include "CoreMinimal.h"
#include "IncubatorRecipeChangeEventDelegate.generated.h"

class USelectableRecipesSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIncubatorRecipeChangeEvent, USelectableRecipesSimulationComponent*, RecipeSelector);

