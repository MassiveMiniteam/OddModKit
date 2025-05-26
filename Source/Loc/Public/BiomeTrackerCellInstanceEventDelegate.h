#pragma once
#include "CoreMinimal.h"
#include "BiomeTrackerCellInstanceEventDelegate.generated.h"

class UBiomeCellInstance;
class UBiomeTrackerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBiomeTrackerCellInstanceEvent, UBiomeTrackerSimulationComponent*, Component, UBiomeCellInstance*, CellInstance);

