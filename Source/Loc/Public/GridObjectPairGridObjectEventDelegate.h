#pragma once
#include "CoreMinimal.h"
#include "GridObjectPairGridObjectEventDelegate.generated.h"

class AGridObject;
class UGridObjectPairSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGridObjectPairGridObjectEvent, UGridObjectPairSimulationComponent*, Component, AGridObject*, GridObject);

