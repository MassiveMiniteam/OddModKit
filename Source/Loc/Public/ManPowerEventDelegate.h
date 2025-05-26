#pragma once
#include "CoreMinimal.h"
#include "ManPowerEventDelegate.generated.h"

class UManpowerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FManPowerEvent, UManpowerSimulationComponent*, Component, int32, Slot);

