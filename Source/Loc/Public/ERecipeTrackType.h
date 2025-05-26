#pragma once
#include "CoreMinimal.h"
#include "ERecipeTrackType.generated.h"

UENUM(BlueprintType)
enum class ERecipeTrackType : uint8 {
    Production,
    Consumption,
    OverProduction,
};

