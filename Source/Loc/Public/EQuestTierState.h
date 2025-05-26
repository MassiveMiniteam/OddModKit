#pragma once
#include "CoreMinimal.h"
#include "EQuestTierState.generated.h"

UENUM(BlueprintType)
enum class EQuestTierState : uint8 {
    Available,
    Next,
    Soon,
    Later,
    Completed,
    Mastered,
    Empty,
};

