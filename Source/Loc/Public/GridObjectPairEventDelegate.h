#pragma once
#include "CoreMinimal.h"
#include "GridObjectPairEventDelegate.generated.h"

class UGridObjectPairSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGridObjectPairEvent, UGridObjectPairSimulationComponent*, Component);

