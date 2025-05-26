#pragma once
#include "CoreMinimal.h"
#include "ActorChainComponent_DelegateDelegate.generated.h"

class UActorChainSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActorChainComponent_Delegate, UActorChainSimulationComponent*, Component);

