#pragma once
#include "CoreMinimal.h"
#include "EChunkHeightFixState.h"
#include "ChunkHeightFixStateArray.generated.h"

USTRUCT(BlueprintType)
struct FChunkHeightFixStateArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EChunkHeightFixState> Array;
    
    LOC_API FChunkHeightFixStateArray();
};

