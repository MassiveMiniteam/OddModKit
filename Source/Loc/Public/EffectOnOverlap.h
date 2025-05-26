#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EffectOnOverlap.generated.h"

class UGameplayEffect;

USTRUCT(BlueprintType)
struct FEffectOnOverlap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffect> Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyEffectOnStartOverlap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyEffectOnTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRemoveEffectOnEndOverlap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMarkAsDeathOnApplication;
    
    LOC_API FEffectOnOverlap();
};

