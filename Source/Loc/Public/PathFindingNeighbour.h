#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EPathfindingWalkableType.h"
#include "PathFindingNeighbour.generated.h"

USTRUCT(BlueprintType)
struct FPathFindingNeighbour {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint GridPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HeightDifference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPathfindingWalkableType WalkableType;
    
    LOC_API FPathFindingNeighbour();
};

