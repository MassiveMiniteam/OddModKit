#pragma once
#include "CoreMinimal.h"
#include "EGenerationCommandType.generated.h"

UENUM(BlueprintType)
enum class EGenerationCommandType : uint8 {
    GenerateTile,
    SpawnCellMetaData,
    SpawnTile,
    UnloadProceduralChunkCells,
    SpawnProceduralChunkCells,
    GenerateProceduralChunkCells,
};

