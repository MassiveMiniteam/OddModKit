#pragma once
#include "CoreMinimal.h"
#include "ETestExitCode.generated.h"

UENUM(BlueprintType)
enum class ETestExitCode : uint8 {
    Successful,
    RuntimeError,
    Timeout,
    TestNotFound,
};

