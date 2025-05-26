#pragma once
#include "CoreMinimal.h"
#include "EProjectileLaunchType.generated.h"

UENUM(BlueprintType)
enum class EProjectileLaunchType : uint8 {
    None,
    Throw,
    Jump,
    Itemize,
    Knockback,
    Suckin,
};

