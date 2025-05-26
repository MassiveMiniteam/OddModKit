#pragma once
#include "CoreMinimal.h"
#include "EDestructionReason.generated.h"

UENUM(BlueprintType)
enum class EDestructionReason : uint8 {
    None,
    ChunkUnload,
    ClearSimulation,
    Gameplay,
    PlayerSpawn,
};

