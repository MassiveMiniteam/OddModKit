#pragma once
#include "CoreMinimal.h"
#include "TokenGeneratorEventDelegate.generated.h"

class UTokenGeneratorSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTokenGeneratorEvent, UTokenGeneratorSimulationComponent*, TokenGenerator);

