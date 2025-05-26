#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BTStateMachineTagEventDelegate.generated.h"

class UBTStateMachineComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBTStateMachineTagEvent, UBTStateMachineComponent*, StateMachine, FGameplayTag, NewState);

