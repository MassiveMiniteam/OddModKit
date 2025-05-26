#pragma once
#include "CoreMinimal.h"
#include "IntPointToConstructableConfig.h"
#include "ArrayOfIntPointToConstructionConfigs.generated.h"

USTRUCT(BlueprintType)
struct FArrayOfIntPointToConstructionConfigs {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPointToConstructableConfig> Array;
    
    LOC_API FArrayOfIntPointToConstructionConfigs();
};

