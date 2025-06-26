#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ItemStack.h"
#include "MinionConfigTagPair.generated.h"

USTRUCT(BlueprintType)
struct FMinionConfigTagPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStack MinionItemStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MinionGroupTag;
    
    LOC_API FMinionConfigTagPair();
};

