#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BTStateMachineStateGroupEventDelegate.generated.h"

class UBTStateMachineComponent;
class UStateGroup;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FBTStateMachineStateGroupEvent, UBTStateMachineComponent*, StateMachine, UStateGroup*, StateGroup, FGameplayTag, OldStateGroupTag, FGameplayTag, NewStateGroupTag);

