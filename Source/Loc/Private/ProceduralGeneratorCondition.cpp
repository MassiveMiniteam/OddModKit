#include "ProceduralGeneratorCondition.h"

UProceduralGeneratorCondition::UProceduralGeneratorCondition() {
}

bool UProceduralGeneratorCondition::IsAllowed_Implementation(UWorldGenerator* WorldGenerator, int32 InSeed, UBiomeCellInstance* TargetCell, UBiomeInstance* TargetBiome) {
    return false;
}


