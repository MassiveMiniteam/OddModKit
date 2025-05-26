#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "Templates/SubclassOf.h"
#include "OnDamageAppliedWithInstigatorDelegate.generated.h"

class AActor;
class UGameplayEffectDamage;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnDamageAppliedWithInstigator, TSubclassOf<UGameplayEffectDamage>, DamageClass, FFixed, Amount, FGameplayTagContainer, Tags, AActor*, Instigator);

