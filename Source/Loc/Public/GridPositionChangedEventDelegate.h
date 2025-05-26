#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridPositionChangedEventDelegate.generated.h"

class UPositionSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGridPositionChangedEvent, UPositionSimulationComponent*, PositionComponent, FIntPoint, LastGridPosition);

