#pragma once
#include "CoreMinimal.h"
#include "InjectedRecipeArray.generated.h"

class URecipeConfig;

USTRUCT(BlueprintType)
struct FInjectedRecipeArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URecipeConfig*> RecipeConfigs;
    
    LOC_API FInjectedRecipeArray();
};

