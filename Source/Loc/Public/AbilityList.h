#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AbilityList.generated.h"

class UGameplayAbility;

USTRUCT(BlueprintType)
struct FAbilityList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UGameplayAbility>> Array;
    
    LOC_API FAbilityList();
};

