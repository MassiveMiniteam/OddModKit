#pragma once
#include "CoreMinimal.h"
#include "ESaveCategory.generated.h"

UENUM(BlueprintType)
enum class ESaveCategory : uint8 {
    Loading,
    Saving,
    LoadBytes,
};

