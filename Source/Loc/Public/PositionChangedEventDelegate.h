#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PositionChangedEventDelegate.generated.h"

class UPositionSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPositionChangedEvent, UPositionSimulationComponent*, PositionComponent, FIntVector, LastPosition);

