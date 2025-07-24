#pragma once
#include "CoreMinimal.h"
#include "ESaveGameCompatibilityError.generated.h"

UENUM(BlueprintType)
enum class ESaveGameCompatibilityError : uint8 {
    None,
    ModMismatch,
    DLCMismatch,
};

