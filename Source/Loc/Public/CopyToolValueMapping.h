#pragma once
#include "CoreMinimal.h"
#include "CopyToolValue.h"
#include "CopyToolValueMapping.generated.h"

USTRUCT(BlueprintType)
struct FCopyToolValueMapping {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString IdentifierString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FCopyToolValue Value;
    
    LOC_API FCopyToolValueMapping();
};

