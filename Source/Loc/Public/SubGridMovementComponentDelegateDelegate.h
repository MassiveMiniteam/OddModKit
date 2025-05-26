#pragma once
#include "CoreMinimal.h"
#include "SubGridMovementComponentDelegateDelegate.generated.h"

class USubGridMovementSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSubGridMovementComponentDelegate, USubGridMovementSimulationComponent*, Component);

