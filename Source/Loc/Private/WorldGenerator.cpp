#include "WorldGenerator.h"

UWorldGenerator::UWorldGenerator() {
    this->WorldConfig = NULL;
    this->StartingCell = NULL;
    this->VillageBiomeInstance = NULL;
    this->LastCachedInstance = NULL;
}

void UWorldGenerator::OnSimulationActorShutDown(ASimulationActor* Actor, EDestructionReason Reason) {
}

FIntVector UWorldGenerator::GetWorldPositionFromNormalizedMapPosition(FVector2D NormalizedMapPosition) {
    return FIntVector{};
}

bool UWorldGenerator::GetVillageCellCenter(FIntVector& OutCenter) {
    return false;
}

UBiomeInstance* UWorldGenerator::GetVillageBiomeInstance() {
    return NULL;
}

bool UWorldGenerator::GetStartingCellCenter(FIntVector& OutCenter) {
    return false;
}

UVoronoiCell* UWorldGenerator::GetStartingCell() {
    return NULL;
}

UBiomeCellInstance* UWorldGenerator::GetRandomBiomeCellInstanceOfType(UBiomeCellConfig* Config, FLocRandom Random) {
    return NULL;
}

FVector2D UWorldGenerator::GetPixelOfGridPosition(FIntPoint GridPosition) {
    return FVector2D{};
}

FVector2D UWorldGenerator::GetNormalizedMapPositionFromWorldPosition(FIntVector WorldPosition) {
    return FVector2D{};
}

FVector2D UWorldGenerator::GetNormalizedMapPosition(FIntPoint GridPosition) {
    return FVector2D{};
}

TArray<UBiomeCellInstance*> UWorldGenerator::GetNeighboursOfCell(UVoronoiCell* Cell) {
    return TArray<UBiomeCellInstance*>();
}

FIntPoint UWorldGenerator::GetCenterPositionForClosestBiomeWithConfig(UBiomeCellConfig* Config, bool& bSucces) {
    return FIntPoint{};
}

FString UWorldGenerator::GetCellConfigDebugText() {
    return TEXT("");
}

TArray<FBiomeCellGenerationDebugBiomeEntry> UWorldGenerator::GetCellConfigDebugInfo() {
    return TArray<FBiomeCellGenerationDebugBiomeEntry>();
}

TArray<UBiomeInstance*> UWorldGenerator::GetBiomeInstances() {
    return TArray<UBiomeInstance*>();
}

TMap<int32, UBiomeCellInstance*> UWorldGenerator::GetBiomeCellInstanceIdMap() {
    return TMap<int32, UBiomeCellInstance*>();
}

UBiomeCellInstance* UWorldGenerator::GetBiomeAt(const FIntPoint& GridPosition, FFixed64& Distance, bool bWithDistance) {
    return NULL;
}

UBiomeInstance* UWorldGenerator::AddBiomeInstance(int32 BiomeSeed) {
    return NULL;
}


