#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GlobalGridCellChangedEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGlobalGridCellChangedEvent, FIntPoint, GridPosition);

