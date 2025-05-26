#pragma once
#include "CoreMinimal.h"
#include "LogicTrainSensorEventDelegate.generated.h"

class ULogicTrainSensor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLogicTrainSensorEvent, ULogicTrainSensor*, TrainSensor);

