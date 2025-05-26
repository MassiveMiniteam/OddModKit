#pragma once
#include "CoreMinimal.h"
#include "PlayerNetworkEventDelegate.generated.h"

class ASimulationActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerNetworkEvent, ASimulationActor*, Player);

