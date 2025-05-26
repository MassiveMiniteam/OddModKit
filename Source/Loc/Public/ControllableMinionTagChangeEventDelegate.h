#pragma once
#include "CoreMinimal.h"
#include "ControllableMinionTagChangeEventDelegate.generated.h"

class UControllableMinionSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FControllableMinionTagChangeEvent, UControllableMinionSimulationComponent*, ControllableMinionComponent);

