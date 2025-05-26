#pragma once
#include "CoreMinimal.h"
#include "ItemizeComponentEventDelegate.generated.h"

class UItemizeSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemizeComponentEvent, UItemizeSimulationComponent*, ItemizeSimulationComponent);

