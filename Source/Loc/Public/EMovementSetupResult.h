#pragma once
#include "CoreMinimal.h"
#include "EMovementSetupResult.generated.h"

UENUM(BlueprintType)
enum class EMovementSetupResult : uint8 {
    TargetAlreadyReached,
    SetupFailed,
    SetupSuccess,
    RequestToTargetAlreadyRunning,
};

