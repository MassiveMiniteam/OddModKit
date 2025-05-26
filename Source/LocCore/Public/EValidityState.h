#pragma once
#include "CoreMinimal.h"
#include "EValidityState.generated.h"

UENUM(BlueprintType)
enum class EValidityState : uint8 {
    Valid,
    Invalid,
};

