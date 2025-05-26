#pragma once
#include "CoreMinimal.h"
#include "OnPathAgentEventDelegate.generated.h"

class APathNetwork;
class UPathNetworkAgentSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPathAgentEvent, APathNetwork*, Instance, UPathNetworkAgentSimulationComponent*, PathAgent);

