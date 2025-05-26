#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnPathAddonGameplayEffectAppliedDelegateDelegate.generated.h"

class UGameplayEffect;
class UGridNetworkAgentSimulationComponent;
class UPathAddOn_ApplyGameplayEffect_SimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPathAddonGameplayEffectAppliedDelegate, const UPathAddOn_ApplyGameplayEffect_SimulationComponent*, Component, UGridNetworkAgentSimulationComponent*, Agent, TSubclassOf<UGameplayEffect>, EffectClass);

