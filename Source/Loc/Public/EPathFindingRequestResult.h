#pragma once
#include "CoreMinimal.h"
#include "EPathFindingRequestResult.generated.h"

UENUM()
enum class EPathFindingRequestResult : int32 {
    Success,
    FailedButClosestPath,
    Fail,
    Cancelled,
};

