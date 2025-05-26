#pragma once
#include "CoreMinimal.h"
#include "CannonComponent_EventDelegate.generated.h"

class UCannonSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCannonComponent_Event, UCannonSimulationComponent*, CannonComponent);

