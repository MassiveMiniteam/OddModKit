#pragma once
#include "CoreMinimal.h"
#include "EGameplayAbilitySelfTargeting.generated.h"

UENUM(BlueprintType)
enum class EGameplayAbilitySelfTargeting : uint8 {
    Yes,
    No,
    IfHitByTargetingClass,
};

