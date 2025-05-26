#pragma once
#include "CoreMinimal.h"
#include "EFactionType.generated.h"

UENUM(BlueprintType)
enum class EFactionType : uint8 {
    None,
    Player,
    Enemy,
    EnvironmentObject,
    Critter,
};

