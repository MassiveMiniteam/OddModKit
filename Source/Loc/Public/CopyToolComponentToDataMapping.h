#pragma once
#include "CoreMinimal.h"
#include "CopyToolPropertyValueWrapper.h"
#include "CopyToolComponentToDataMapping.generated.h"

USTRUCT(BlueprintType)
struct FCopyToolComponentToDataMapping {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCopyToolPropertyValueWrapper> Data;
    
    LOC_API FCopyToolComponentToDataMapping();
};

