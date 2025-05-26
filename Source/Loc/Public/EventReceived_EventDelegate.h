#pragma once
#include "CoreMinimal.h"
#include "EventReceived_EventDelegate.generated.h"

class UEventReceiverPresentationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventReceived_Event, UEventReceiverPresentationComponent*, Component);

