#pragma once
#include "CoreMinimal.h"
#include "ETickIntervalMode.generated.h"

UENUM(BlueprintType)
enum class ETickIntervalMode : uint8 {
    FixedInterval,
    FixedMarks,
};

