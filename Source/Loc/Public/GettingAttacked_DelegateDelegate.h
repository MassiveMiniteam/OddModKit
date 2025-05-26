#pragma once
#include "CoreMinimal.h"
#include "GettingAttacked_DelegateDelegate.generated.h"

class ASimulationActor;
class UGameplayAbility;
class UGettingAttackedSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FGettingAttacked_Delegate, UGettingAttackedSimulationComponent*, Component, ASimulationActor*, Instigator, UGameplayAbility*, Ability, bool, bSuccess);

