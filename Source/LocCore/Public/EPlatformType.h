#pragma once
#include "CoreMinimal.h"
#include "EPlatformType.generated.h"

UENUM(BlueprintType)
enum class EPlatformType : uint8 {
    None,
    Windows,
    Stadia,
    PS4,
    PS5,
    Switch,
    XBoxOne,
    XBoxSeries,
    Mac,
    Linux,
    IOS,
    Android,
};

