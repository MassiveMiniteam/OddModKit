#pragma once
#include "CoreMinimal.h"
#include "EGridDirectionVisualizationType.generated.h"

UENUM(BlueprintType)
enum class EGridDirectionVisualizationType : uint8 {
    End,
    Straight,
    Curve,
    TJunction,
    XJunction,
};

