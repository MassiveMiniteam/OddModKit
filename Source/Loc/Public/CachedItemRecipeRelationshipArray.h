#pragma once
#include "CoreMinimal.h"
#include "CachedItemRecipeRelationship.h"
#include "CachedItemRecipeRelationshipArray.generated.h"

USTRUCT(BlueprintType)
struct FCachedItemRecipeRelationshipArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCachedItemRecipeRelationship> Relationships;
    
    LOC_API FCachedItemRecipeRelationshipArray();
};

