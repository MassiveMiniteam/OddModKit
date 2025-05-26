#pragma once
#include "CoreMinimal.h"
#include "BooleanOperation.generated.h"

UENUM(BlueprintType)
enum class BooleanOperation : uint8 {
    AND,
    OR,
    NOT,
    XOR,
    NAND,
    NOR,
    XNOR,
};

