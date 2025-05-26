#pragma once
#include "CoreMinimal.h"
#include "EMenuShowForDevice.generated.h"

UENUM(BlueprintType)
enum class EMenuShowForDevice : uint8 {
    GamepadAndKeyboard,
    GamepadOnly,
    KeyboardMouseOnly,
};

