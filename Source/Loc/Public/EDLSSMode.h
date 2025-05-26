#pragma once
#include "CoreMinimal.h"
#include "EDLSSMode.generated.h"

UENUM(BlueprintType)
enum class EDLSSMode : uint8 {
    Off,
    Auto,
    DLAA,
    UltraQuality,
    Quality,
    Balanced,
    Performance,
    UltraPerformance,
};

