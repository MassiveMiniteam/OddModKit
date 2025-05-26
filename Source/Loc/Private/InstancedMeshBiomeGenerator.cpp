#include "InstancedMeshBiomeGenerator.h"

UInstancedMeshBiomeGenerator::UInstancedMeshBiomeGenerator() {
    this->Material = NULL;
    this->HeightOverwrite = 500.00f;
    this->MinDistanceToEdge = 2;
    this->bInvert = false;
    this->InstancedStaticMeshComponent = NULL;
    this->bAutoGenerateToAnotherBiome = true;
}


