#pragma once
#include "CoreMinimal.h"
#include "EMovementEndResult.generated.h"

UENUM(BlueprintType)
enum class EMovementEndResult : uint8 {
    TargetReached,
    Timeout,
    Cancelled,
    Failed,
};

