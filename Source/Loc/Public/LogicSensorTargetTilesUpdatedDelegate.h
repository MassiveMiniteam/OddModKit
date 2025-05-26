#pragma once
#include "CoreMinimal.h"
#include "LogicSensorTargetTilesUpdatedDelegate.generated.h"

class ULogicSensorBaseSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLogicSensorTargetTilesUpdated, ULogicSensorBaseSimulationComponent*, LogicSensor);

