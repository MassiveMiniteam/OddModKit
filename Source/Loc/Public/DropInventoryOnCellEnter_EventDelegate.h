#pragma once
#include "CoreMinimal.h"
#include "DropInventoryOnCellEnter_EventDelegate.generated.h"

class UDropInventoryOnCellEnterComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDropInventoryOnCellEnter_Event, UDropInventoryOnCellEnterComponent*, Component);

