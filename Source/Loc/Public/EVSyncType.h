#pragma once
#include "CoreMinimal.h"
#include "EVSyncType.generated.h"

UENUM(BlueprintType)
enum class EVSyncType : uint8 {
    None,
    Full,
    Half,
};

