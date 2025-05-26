#pragma once
#include "CoreMinimal.h"
#include "ECraftingStatusCode.h"
#include "CraftingResponseEventDelegate.generated.h"

class URecipeConfig;
class URecipeProcessorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCraftingResponseEvent, URecipeProcessorSimulationComponent*, Component, URecipeConfig*, Recipe, ECraftingStatusCode, ResponseCode);

