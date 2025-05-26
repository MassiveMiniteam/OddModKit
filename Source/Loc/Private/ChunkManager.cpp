#include "ChunkManager.h"

UChunkManager::UChunkManager() {
    this->Grid = NULL;
    this->WorldGenerator = NULL;
}

void UChunkManager::OnSimulation(ASimulationManager* SimulationManager) {
}

UGridChunk* UChunkManager::LoadChunk(const FChunkPosition& ChunkPosition) {
    return NULL;
}

void UChunkManager::GetPositionsForBiomeCellConfig(UBiomeCellConfig* BiomeCellConfig, TArray<FIntPoint>& OutPositions) {
}

FChunkPosition UChunkManager::GetChunkPositionForPosition(const FIntPoint& position) const {
    return FChunkPosition{};
}

FIntPoint UChunkManager::GetChunkGridOrigin(FChunkPosition ChunkPosition) {
    return FIntPoint{};
}

UGridChunk* UChunkManager::GetChunkAtGridPosition(const FIntPoint& GridPosition) {
    return NULL;
}


