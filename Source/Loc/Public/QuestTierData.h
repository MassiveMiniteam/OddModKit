#pragma once
#include "CoreMinimal.h"
#include "EQuestTier.h"
#include "QuestTierData.generated.h"

class UQuestConfig;

USTRUCT(BlueprintType)
struct FQuestTierData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuestTier Tier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UQuestConfig*> Quests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HighestVisualIndex;
    
    LOC_API FQuestTierData();
};

