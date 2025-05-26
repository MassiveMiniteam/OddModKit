#pragma once
#include "CoreMinimal.h"
#include "EQuestTier.generated.h"

UENUM(BlueprintType)
enum class EQuestTier : uint8 {
    Tier1,
    Tier2,
    Tier3,
    Tier4,
    Tier5,
    Tier6,
    Tier7,
    Tier8,
    Tier9,
    Tier10,
    Max,
};

