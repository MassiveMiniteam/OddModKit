#pragma once
#include "CoreMinimal.h"
#include "EPositionPushbackType.generated.h"

UENUM(BlueprintType)
enum class EPositionPushbackType : uint8 {
    None,
    Player,
    Minion,
    Enemy,
};

