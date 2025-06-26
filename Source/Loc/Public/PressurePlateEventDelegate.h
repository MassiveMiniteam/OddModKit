#pragma once
#include "CoreMinimal.h"
#include "PressurePlateEventDelegate.generated.h"

class UPathAddOn_PressurePlate_SimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPressurePlateEvent, UPathAddOn_PressurePlate_SimulationComponent*, PlateComponent);

