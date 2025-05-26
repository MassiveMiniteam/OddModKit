#pragma once
#include "CoreMinimal.h"
#include "CanCraftDelegateDelegate.generated.h"

class URecipeConfig;
class URecipeProcessorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(bool, FCanCraftDelegate, URecipeProcessorSimulationComponent*, Component, URecipeConfig*, Recipe);

