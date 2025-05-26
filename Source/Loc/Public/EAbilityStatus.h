#pragma once
#include "CoreMinimal.h"
#include "EAbilityStatus.generated.h"

UENUM(BlueprintType)
enum class EAbilityStatus : uint8 {
    Inactive,
    Running,
};

