#pragma once
#include "CoreMinimal.h"
#include "ECapacitySensorMode.generated.h"

UENUM(BlueprintType)
enum class ECapacitySensorMode : uint8 {
    Absolute,
    Percentage,
};

