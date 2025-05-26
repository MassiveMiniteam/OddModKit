#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MinionConfigTagPair.generated.h"

class UItemMinionConfig;

USTRUCT(BlueprintType)
struct FMinionConfigTagPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemMinionConfig* MinionConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MinionGroupTag;
    
    LOC_API FMinionConfigTagPair();
};

