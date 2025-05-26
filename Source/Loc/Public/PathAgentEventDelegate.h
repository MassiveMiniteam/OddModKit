#pragma once
#include "CoreMinimal.h"
#include "PathAgentEventDelegate.generated.h"

class UPathNetworkAgentSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPathAgentEvent, UPathNetworkAgentSimulationComponent*, Agent);

