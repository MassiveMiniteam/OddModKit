#pragma once
#include "CoreMinimal.h"
#include "GameplayFixedStatPair.h"
#include "GameplayFixedStatMap.generated.h"

USTRUCT(BlueprintType)
struct FGameplayFixedStatMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FGameplayFixedStatPair> BaseStatPairs;
    
    LOC_API FGameplayFixedStatMap();
};

