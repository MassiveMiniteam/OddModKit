#pragma once
#include "CoreMinimal.h"
#include "EAudioVolumeType.generated.h"

UENUM(BlueprintType)
enum class EAudioVolumeType : uint8 {
    Master,
    Music,
    SFX,
    Ambience,
    Workstations,
    Minions,
};

