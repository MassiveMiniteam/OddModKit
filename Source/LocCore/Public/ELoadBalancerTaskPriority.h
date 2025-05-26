#pragma once
#include "CoreMinimal.h"
#include "ELoadBalancerTaskPriority.generated.h"

UENUM(BlueprintType)
enum class ELoadBalancerTaskPriority : uint8 {
    Low,
    Normal,
    High,
};

