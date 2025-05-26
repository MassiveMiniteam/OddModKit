#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MovedGridPositionDelegate.generated.h"

class UPositionHeadingSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FMovedGridPosition, UPositionHeadingSimulationComponent*, PositionHeading, FIntPoint, LastPosition, FIntPoint, NewPosition);

