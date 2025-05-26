#pragma once
#include "CoreMinimal.h"
#include "IncubationComponentEventDelegate.generated.h"

class UIncubationRecipeProcessorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIncubationComponentEvent, UIncubationRecipeProcessorSimulationComponent*, IncubationProcessor);

