#pragma once
#include "CoreMinimal.h"
#include "EGameplayStatModifierType.generated.h"

UENUM(BlueprintType)
enum class EGameplayStatModifierType : uint8 {
    Add,
    Multiply,
};

