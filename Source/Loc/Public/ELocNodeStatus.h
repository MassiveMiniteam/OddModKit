#pragma once
#include "CoreMinimal.h"
#include "ELocNodeStatus.generated.h"

UENUM(BlueprintType)
enum class ELocNodeStatus : uint8 {
    None,
    Failure,
    Success,
    Running,
};

