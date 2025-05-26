#pragma once
#include "CoreMinimal.h"
#include "EOutDirectionStates.generated.h"

UENUM(BlueprintType)
enum class EOutDirectionStates : uint8 {
    NextDirection,
    NotNextDirection,
    NoPath,
};

