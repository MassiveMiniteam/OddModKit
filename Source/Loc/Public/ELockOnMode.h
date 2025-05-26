#pragma once
#include "CoreMinimal.h"
#include "ELockOnMode.generated.h"

UENUM(BlueprintType)
enum class ELockOnMode : uint8 {
    Locked,
    Free,
    RadiusAround,
};

