#pragma once
#include "CoreMinimal.h"
#include "CarryComponent_DelegateDelegate.generated.h"

class UCarrySimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCarryComponent_Delegate, UCarrySimulationComponent*, CarryComponent);

