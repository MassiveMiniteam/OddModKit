#pragma once
#include "CoreMinimal.h"
#include "BTStateMachineStateEventDelegate.generated.h"

class UBTStateMachineComponent;
class UBaseState;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBTStateMachineStateEvent, UBTStateMachineComponent*, StateMachine, UBaseState*, NewState);

