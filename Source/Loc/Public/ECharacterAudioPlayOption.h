#pragma once
#include "CoreMinimal.h"
#include "ECharacterAudioPlayOption.generated.h"

UENUM(BlueprintType)
enum class ECharacterAudioPlayOption : uint8 {
    Sound2D,
    AtLocation,
    AttachedToActor,
};

