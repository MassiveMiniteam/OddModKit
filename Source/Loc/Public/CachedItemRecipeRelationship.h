#pragma once
#include "CoreMinimal.h"
#include "CachedItemRecipeRelationshipItem.h"
#include "CachedItemRecipeRelationship.generated.h"

class ASimulationActor;

USTRUCT(BlueprintType)
struct FCachedItemRecipeRelationship {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ASimulationActor> Workstation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCachedItemRecipeRelationshipItem> RecipeRelationships;
    
    LOC_API FCachedItemRecipeRelationship();
};

