#pragma once
#include "CoreMinimal.h"
#include "OnSimulationPositionUpdatedDelegate.generated.h"

class UPositionSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSimulationPositionUpdated, UPositionSimulationComponent*, Component);

