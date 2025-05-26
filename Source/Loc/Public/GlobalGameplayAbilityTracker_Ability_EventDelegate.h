#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GlobalGameplayAbilityTracker_Ability_EventDelegate.generated.h"

class ASimulationActor;
class UGameplayAbility;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGlobalGameplayAbilityTracker_Ability_Event, TSubclassOf<UGameplayAbility>, Ability, ASimulationActor*, Owner);

