#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"
#include "TagAndGameplayEffectClass.generated.h"

class UGameplayEffect;

USTRUCT(BlueprintType)
struct FTagAndGameplayEffectClass {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTag SimulationActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffect> GameplayEffectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bDecaysIfNotNaturalElement;
    
    LOC_API FTagAndGameplayEffectClass();
};

