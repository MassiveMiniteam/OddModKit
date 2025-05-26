#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ConstructionToolsCursorGridPositionEventDelegate.generated.h"

class UInputContextConstructionToolsCursor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FConstructionToolsCursorGridPositionEvent, UInputContextConstructionToolsCursor*, InputContext, FIntPoint, GridPosition);

