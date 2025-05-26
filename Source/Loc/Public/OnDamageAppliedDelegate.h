#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "Templates/SubclassOf.h"
#include "OnDamageAppliedDelegate.generated.h"

class UGameplayEffectDamage;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDamageApplied, TSubclassOf<UGameplayEffectDamage>, DamageClass, FFixed, Amount, FGameplayTagContainer, Tags);

