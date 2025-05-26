#pragma once
#include "CoreMinimal.h"
#include "ControllableMinionCallbackEventDelegate.generated.h"

class ASimulationActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FControllableMinionCallbackEvent, ASimulationActor*, Minion);

