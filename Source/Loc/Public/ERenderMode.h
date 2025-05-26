#pragma once
#include "CoreMinimal.h"
#include "ERenderMode.generated.h"

UENUM(BlueprintType)
enum class ERenderMode : uint8 {
    Dx11,
    Dx12,
    Vulkan,
};

