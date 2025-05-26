#pragma once
#include "CoreMinimal.h"
#include "EBossResetReason.generated.h"

UENUM(BlueprintType)
enum class EBossResetReason : uint8 {
    PlayerInteraction,
    FullyCorrupted,
    Other,
};

