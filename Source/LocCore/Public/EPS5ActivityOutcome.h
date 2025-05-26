#pragma once
#include "CoreMinimal.h"
#include "EPS5ActivityOutcome.generated.h"

UENUM(BlueprintType)
enum class EPS5ActivityOutcome : uint8 {
    Completed,
    Failed,
    Cancelled,
};

