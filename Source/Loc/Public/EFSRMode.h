#pragma once
#include "CoreMinimal.h"
#include "EFSRMode.generated.h"

UENUM(BlueprintType)
enum class EFSRMode : uint8 {
    Off,
    Quality,
    Balanced,
    Performance,
    UltraPerformance,
};

