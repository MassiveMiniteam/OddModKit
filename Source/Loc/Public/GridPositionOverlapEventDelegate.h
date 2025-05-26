#pragma once
#include "CoreMinimal.h"
#include "GridPositionOverlapEventDelegate.generated.h"

class UPositionSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGridPositionOverlapEvent, UPositionSimulationComponent*, ThisComponent, UPositionSimulationComponent*, OtherComponent);

