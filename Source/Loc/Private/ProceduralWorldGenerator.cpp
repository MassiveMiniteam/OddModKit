#include "ProceduralWorldGenerator.h"

UProceduralWorldGenerator::UProceduralWorldGenerator() {
}

void UProceduralWorldGenerator::NativeGenerate_Implementation(UWorldGenerator* WorldGenerator, int32 InSeed, TArray<UBiomeInstance*>& BiomeInstances, TArray<UBiomeCellInstance*>& CellInstances) {
}

FString UProceduralWorldGenerator::GetDescription() {
    return TEXT("");
}

void UProceduralWorldGenerator::Generate(UWorldGenerator* WorldGenerator, int32 InSeed, TArray<UBiomeInstance*>& BiomeInstances, TArray<UBiomeCellInstance*>& CellInstances) {
}


