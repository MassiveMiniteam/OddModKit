#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayEffect.h"
#include "GameplayEffectDamage.generated.h"

class UNiagaraSystem;

UCLASS(Abstract, Blueprintable)
class LOC_API UGameplayEffectDamage : public UGameplayEffect {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag DamageMultiplierOnTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> NiagaraSystem;
    
public:
    UGameplayEffectDamage();

};

