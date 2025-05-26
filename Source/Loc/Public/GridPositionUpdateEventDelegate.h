#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridPositionUpdateEventDelegate.generated.h"

class AGridObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGridPositionUpdateEvent, AGridObject*, GridObject, FIntPoint, GridPosition);

