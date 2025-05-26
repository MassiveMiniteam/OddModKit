#pragma once
#include "CoreMinimal.h"
#include "OnItemCounterChangedDelegate.generated.h"

class UPathAddOn_ItemThroughputMeter_SimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemCounterChanged, UPathAddOn_ItemThroughputMeter_SimulationComponent*, ItemThroughputMeter);

