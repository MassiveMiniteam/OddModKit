#pragma once
#include "CoreMinimal.h"
#include "OnDemoBiomeRestrictionEventDelegate.generated.h"

class UDemoBiomeRestrictionSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDemoBiomeRestrictionEvent, UDemoBiomeRestrictionSimulationComponent*, DemoBiomeRestrictionSimulationComponent);

