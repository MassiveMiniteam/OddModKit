#pragma once
#include "CoreMinimal.h"
#include "ProceduralWorldGeneratorBiomeSortItem.generated.h"

class UProceduralWorldGenerator;

USTRUCT(BlueprintType)
struct FProceduralWorldGeneratorBiomeSortItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProceduralWorldGenerator* Generator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SortIndex;
    
    LOC_API FProceduralWorldGeneratorBiomeSortItem();
};

