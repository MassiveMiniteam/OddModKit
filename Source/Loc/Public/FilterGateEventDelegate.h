#pragma once
#include "CoreMinimal.h"
#include "FilterGateEventDelegate.generated.h"

class ULogicFilterGateSimulation;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFilterGateEvent, ULogicFilterGateSimulation*, Gate);

