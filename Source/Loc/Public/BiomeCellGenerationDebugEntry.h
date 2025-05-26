#pragma once
#include "CoreMinimal.h"
#include "BiomeCellGenerationDebugEntry.generated.h"

class UBiomeCellConfig;

USTRUCT(BlueprintType)
struct FBiomeCellGenerationDebugEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeCellConfig* BiomeCellConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Amount;
    
    LOC_API FBiomeCellGenerationDebugEntry();
};

