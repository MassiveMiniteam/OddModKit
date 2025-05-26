#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EPathfindingWalkableType.h"
#include "PathFindingGridConnection.generated.h"

USTRUCT(BlueprintType)
struct FPathFindingGridConnection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint To;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EPathfindingWalkableType WalkableType;
    
    LOC_API FPathFindingGridConnection();
};

