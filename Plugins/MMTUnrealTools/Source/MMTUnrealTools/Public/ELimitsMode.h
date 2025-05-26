#pragma once
#include "CoreMinimal.h"
#include "ELimitsMode.generated.h"

UENUM(BlueprintType)
enum class ELimitsMode : uint8 {
    NoRounding,
    RoundTo10,
};

