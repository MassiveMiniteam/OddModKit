#pragma once
#include "CoreMinimal.h"
#include "GameplayStatModifier.h"
#include "GameplayStatModifierArray.generated.h"

USTRUCT(BlueprintType)
struct FGameplayStatModifierArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FGameplayStatModifier> Array;
    
    LOC_API FGameplayStatModifierArray();
};

