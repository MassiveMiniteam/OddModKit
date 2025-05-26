#pragma once
#include "CoreMinimal.h"
#include "CachedItemRecipeRelationshipItem.generated.h"

class URecipeConfig;

USTRUCT(BlueprintType)
struct FCachedItemRecipeRelationshipItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URecipeConfig* RecipeConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInput;
    
    LOC_API FCachedItemRecipeRelationshipItem();
};

