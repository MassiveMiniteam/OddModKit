#pragma once
#include "CoreMinimal.h"
#include "QuestOverviewCategoryCollection.generated.h"

class UQuestOverviewCategory;

USTRUCT(BlueprintType)
struct FQuestOverviewCategoryCollection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UQuestOverviewCategory*> Data;
    
    LOC_API FQuestOverviewCategoryCollection();
};

