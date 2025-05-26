#pragma once
#include "CoreMinimal.h"
#include "QuestTierData.h"
#include "QuestTierCollection.generated.h"

USTRUCT(BlueprintType)
struct FQuestTierCollection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FQuestTierData> Data;
    
    LOC_API FQuestTierCollection();
};

