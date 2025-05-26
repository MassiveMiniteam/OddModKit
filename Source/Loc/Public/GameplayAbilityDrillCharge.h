#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "GameplayAbility.h"
#include "Templates/SubclassOf.h"
#include "GameplayAbilityDrillCharge.generated.h"

class UGameplayEffectDamage;

UCLASS(Blueprintable)
class LOC_API UGameplayAbilityDrillCharge : public UGameplayAbility {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AttackAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 AttackRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 AttackOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffectDamage> DamageClass;
    
    UGameplayAbilityDrillCharge();

    UFUNCTION(BlueprintCallable)
    void ApplyDamage();
    
};

