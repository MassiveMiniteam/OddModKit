#pragma once
#include "CoreMinimal.h"
#include "EInputDefaultActionType.generated.h"

UENUM(BlueprintType)
enum class EInputDefaultActionType : uint8 {
    None,
    UIAccept,
    UICancel,
    UIMoveLeft,
    UIMoveRight,
    UIMoveUp,
    UIMoveDown,
    UIActionTop,
    UIActionLeft,
};

