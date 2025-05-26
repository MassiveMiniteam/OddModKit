#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "GameplayEffectSpreading.h"
#include "Templates/SubclassOf.h"
#include "GameplayEffectDiggableSpreadingAOE.generated.h"

class UGameplayEffectDamage;

UCLASS(Blueprintable)
class LOC_API UGameplayEffectDiggableSpreadingAOE : public UGameplayEffectSpreading {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed DamageMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffectDamage> DamageClass;
    
    UGameplayEffectDiggableSpreadingAOE();

};

