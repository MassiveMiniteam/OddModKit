#pragma once
#include "CoreMinimal.h"
#include "EBranchInputActioKeyState.generated.h"

UENUM(BlueprintType)
enum class EBranchInputActioKeyState : uint8 {
    Pressed,
    Released,
};

