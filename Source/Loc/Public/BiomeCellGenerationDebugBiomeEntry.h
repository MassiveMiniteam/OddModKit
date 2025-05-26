#pragma once
#include "CoreMinimal.h"
#include "BiomeCellGenerationDebugEntry.h"
#include "BiomeCellGenerationDebugBiomeEntry.generated.h"

class UBiomeConfig;

USTRUCT(BlueprintType)
struct FBiomeCellGenerationDebugBiomeEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeConfig* Biome;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBiomeCellGenerationDebugEntry> BiomeCellsEntries;
    
    LOC_API FBiomeCellGenerationDebugBiomeEntry();
};

