#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameplayEffectClassAndConditions.generated.h"

class UActorConditionStrategy;
class UGameplayEffect;

USTRUCT(BlueprintType)
struct FGameplayEffectClassAndConditions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffect> EffectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UActorConditionStrategy>> ConditionsOnOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UActorConditionStrategy>> ConditionsOnAttacker;
    
    LOC_API FGameplayEffectClassAndConditions();
};

