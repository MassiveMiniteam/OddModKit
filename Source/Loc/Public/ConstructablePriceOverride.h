#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ItemStack.h"
#include "ConstructablePriceOverride.generated.h"

USTRUCT(BlueprintType)
struct FConstructablePriceOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> Price;
    
    LOC_API FConstructablePriceOverride();
};

