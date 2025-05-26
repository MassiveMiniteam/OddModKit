#pragma once
#include "CoreMinimal.h"
#include "CannonPropertiesUpdated_EventDelegate.generated.h"

class UCannonSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCannonPropertiesUpdated_Event, UCannonSimulationComponent*, CannonComponent);

