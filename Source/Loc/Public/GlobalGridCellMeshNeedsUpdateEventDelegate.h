#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GlobalGridCellMeshNeedsUpdateEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGlobalGridCellMeshNeedsUpdateEvent, FIntPoint, GridPosition, bool, bIsHeightChange);

