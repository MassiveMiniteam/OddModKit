#pragma once
#include "CoreMinimal.h"
#include "ESpawnPattern.generated.h"

UENUM(BlueprintType)
enum class ESpawnPattern : uint8 {
    Random,
    InToOut,
};

