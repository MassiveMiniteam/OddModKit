#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UnlockableToAnimationMapping.generated.h"

class UUnlockableDataAsset;

USTRUCT(BlueprintType)
struct FUnlockableToAnimationMapping {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UUnlockableDataAsset*, FGameplayTag> Mapping;
    
    LOC_API FUnlockableToAnimationMapping();
};

