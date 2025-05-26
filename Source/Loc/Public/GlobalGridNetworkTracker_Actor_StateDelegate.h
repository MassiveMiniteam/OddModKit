#pragma once
#include "CoreMinimal.h"
#include "GlobalGridNetworkTracker_Actor_StateDelegate.generated.h"

class UPathNetworkAgentSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGlobalGridNetworkTracker_Actor_State, UPathNetworkAgentSimulationComponent*, Agent);

