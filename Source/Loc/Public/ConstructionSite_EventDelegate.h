#pragma once
#include "CoreMinimal.h"
#include "ConstructionSite_EventDelegate.generated.h"

class UConstructionSiteObjectSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FConstructionSite_Event, UConstructionSiteObjectSimulationComponent*, ConstructionSiteSimulationComponent);

