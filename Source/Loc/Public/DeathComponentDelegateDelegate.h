#pragma once
#include "CoreMinimal.h"
#include "DeathComponentDelegateDelegate.generated.h"

class UDespawnOnDeathSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeathComponentDelegate, UDespawnOnDeathSimulationComponent*, DeathSimulationComponent);

