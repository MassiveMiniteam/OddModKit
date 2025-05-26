#pragma once
#include "CoreMinimal.h"
#include "InputContextDragPlacementEventDelegate.generated.h"

class UInputContextDragPlacement;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInputContextDragPlacementEvent, UInputContextDragPlacement*, InputContext);

