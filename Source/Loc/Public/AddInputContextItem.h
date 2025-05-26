#pragma once
#include "CoreMinimal.h"
#include "AddInputContextItem.generated.h"

class UInputContext;

USTRUCT(BlueprintType)
struct FAddInputContextItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContext* Context;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContext* BelowContext;
    
    LOC_API FAddInputContextItem();
};

