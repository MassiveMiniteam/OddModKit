#pragma once
#include "CoreMinimal.h"
#include "EGameplayEffectStackingPolicy.generated.h"

UENUM(BlueprintType)
enum class EGameplayEffectStackingPolicy : uint8 {
    CreateNewInstance,
    ResetDuration,
    StackAndResetDuration,
    JustStack,
};

