#pragma once
#include "CoreMinimal.h"
#include "EPathfindingWalkableType.generated.h"

UENUM(BlueprintType)
enum class EPathfindingWalkableType : uint8 {
    NotWalkable,
    Walkable,
    JumpUp,
    JumpDown,
};

