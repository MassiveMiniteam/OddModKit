#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridCellChangedEventDelegate.generated.h"

class AGridObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGridCellChangedEvent, AGridObject*, GridObject, FIntPoint, GridPosition);

