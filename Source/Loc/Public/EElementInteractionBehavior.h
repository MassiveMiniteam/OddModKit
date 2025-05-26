#pragma once
#include "CoreMinimal.h"
#include "EElementInteractionBehavior.generated.h"

UENUM(BlueprintType)
enum class EElementInteractionBehavior : uint8 {
    Block,
    Ignore,
    ReduceIntensity,
    AddIntensity,
};

