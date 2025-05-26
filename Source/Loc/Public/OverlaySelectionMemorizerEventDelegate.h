#pragma once
#include "CoreMinimal.h"
#include "OverlaySelectionMemorizerEventDelegate.generated.h"

class UOverlaySelectionMemorizerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOverlaySelectionMemorizerEvent, UOverlaySelectionMemorizerSimulationComponent*, SimulationComponent);

