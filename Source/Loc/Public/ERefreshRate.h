#pragma once
#include "CoreMinimal.h"
#include "ERefreshRate.generated.h"

UENUM(BlueprintType)
enum class ERefreshRate : uint8 {
    RefreshRate_60Hz,
    RefreshRate_120Hz,
};

