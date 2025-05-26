#pragma once
#include "CoreMinimal.h"
#include "EGameplayEffectSuccessionPolicy.generated.h"

UENUM(BlueprintType)
enum class EGameplayEffectSuccessionPolicy : uint8 {
    Always,
    OnlyOnDeath,
    NotOnDeath,
};

