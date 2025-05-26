#pragma once
#include "CoreMinimal.h"
#include "ProceduralWorldGeneratorCellSortItem.generated.h"

class UProceduralCellGenerator;

USTRUCT(BlueprintType)
struct FProceduralWorldGeneratorCellSortItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProceduralCellGenerator* Generator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SortIndex;
    
    LOC_API FProceduralWorldGeneratorCellSortItem();
};

