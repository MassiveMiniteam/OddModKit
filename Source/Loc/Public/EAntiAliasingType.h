#pragma once
#include "CoreMinimal.h"
#include "EAntiAliasingType.generated.h"

UENUM(BlueprintType)
enum class EAntiAliasingType : uint8 {
    None,
    FXAA,
    TemporalAA,
    MSAA,
    TSR,
    DLSS = 100,
    FSR,
    XESS,
};

