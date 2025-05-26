#pragma once
#include "CoreMinimal.h"
#include "QuestCollection.generated.h"

class UQuestConfig;

USTRUCT(BlueprintType)
struct FQuestCollection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UQuestConfig*> Data;
    
    LOC_API FQuestCollection();
};

