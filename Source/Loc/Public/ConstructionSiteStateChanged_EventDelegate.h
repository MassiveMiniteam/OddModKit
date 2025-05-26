#pragma once
#include "CoreMinimal.h"
#include "EConstructionSiteState.h"
#include "ConstructionSiteStateChanged_EventDelegate.generated.h"

class UConstructionSiteObjectSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FConstructionSiteStateChanged_Event, UConstructionSiteObjectSimulationComponent*, ConstructionSiteSimulationComponent, EConstructionSiteState, ConstructionSiteState);

