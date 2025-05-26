#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EPathfindingWalkableType.h"
#include "PathFindingConnection.generated.h"

USTRUCT(BlueprintType)
struct FPathFindingConnection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector To;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EPathfindingWalkableType WalkableType;
    
    LOC_API FPathFindingConnection();
};

