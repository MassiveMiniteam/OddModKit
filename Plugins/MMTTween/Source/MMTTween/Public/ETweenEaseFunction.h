#pragma once
#include "CoreMinimal.h"
#include "ETweenEaseFunction.generated.h"

UENUM(BlueprintType)
enum class ETweenEaseFunction : uint8 {
    Linear,
    QuadIn,
    QuadOut,
    QuadInOut,
    CubicIn,
    CubicOut,
    CubicInOut,
    OutBounce,
};

