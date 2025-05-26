#pragma once
#include "CoreMinimal.h"
#include "EHeadingComponentTurnTypes.generated.h"

UENUM(BlueprintType)
enum class EHeadingComponentTurnTypes : uint8 {
    Straight,
    Left,
    Right,
    UTurn,
};

