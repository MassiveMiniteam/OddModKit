#pragma once
#include "CoreMinimal.h"
#include "TrainStopComponent_DelegateDelegate.generated.h"

class UTrainStopStationSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTrainStopComponent_Delegate, UTrainStopStationSimulationComponent*, Component);

