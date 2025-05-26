#pragma once
#include "CoreMinimal.h"
#include "ECapacitySensorCompareRule.generated.h"

UENUM(BlueprintType)
enum class ECapacitySensorCompareRule : uint8 {
    Above,
    Below,
};

