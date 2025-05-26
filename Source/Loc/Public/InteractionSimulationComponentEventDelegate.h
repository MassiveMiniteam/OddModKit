#pragma once
#include "CoreMinimal.h"
#include "InteractionSimulationComponentEventDelegate.generated.h"

class UInteractionSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractionSimulationComponentEvent, UInteractionSimulationComponent*, Component);

