#pragma once
#include "CoreMinimal.h"
#include "OnLogicEventDelegate.generated.h"

class ULogicConnectionSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLogicEvent, ULogicConnectionSimulationComponent*, Input);

