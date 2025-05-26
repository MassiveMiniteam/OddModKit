#pragma once
#include "CoreMinimal.h"
#include "ActorQueueComponent_DelegateDelegate.generated.h"

class UActorQueueSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActorQueueComponent_Delegate, UActorQueueSimulationComponent*, Component);

