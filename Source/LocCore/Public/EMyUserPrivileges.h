#pragma once
#include "CoreMinimal.h"
#include "EMyUserPrivileges.generated.h"

UENUM(BlueprintType)
enum class EMyUserPrivileges : uint8 {
    CanPlay,
    CanPlayOnline,
    CanCommunicateOnline,
    CanUseUserGeneratedContent,
    CanUserCrossPlay,
};

