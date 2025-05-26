#pragma once
#include "CoreMinimal.h"
#include "ERadialSpawnerTargetTileRequirement.generated.h"

UENUM(BlueprintType)
enum class ERadialSpawnerTargetTileRequirement : uint8 {
    Empty,
    Walkable,
    NotHigher,
};

