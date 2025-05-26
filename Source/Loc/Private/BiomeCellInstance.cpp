#include "BiomeCellInstance.h"

UBiomeCellInstance::UBiomeCellInstance() {
    this->WorldGenerator = NULL;
    this->CellID = 0;
    this->AverageHeight = 0;
    this->BiomeInstance = NULL;
    this->Cell = NULL;
    this->CellSeed = 0;
    this->CellConfig = NULL;
    this->bIsLoaded = false;
}

FIntVector UBiomeCellInstance::GetWorldCenterPosition() {
    return FIntVector{};
}

void UBiomeCellInstance::GetEdges(TArray<FIntVector>& EdgeStartPoints, TArray<FIntVector>& EdgeEndPoints) {
}


