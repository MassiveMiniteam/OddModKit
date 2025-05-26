#include "WorldMapDataComponent.h"

UWorldMapDataComponent::UWorldMapDataComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MapTexture_Terrain = NULL;
    this->MapTexture_TerrainIDs = NULL;
    this->MapTexture_Buildings = NULL;
    this->MapTexture_Paths = NULL;
    this->MapTexture_Paint = NULL;
    this->Grid = NULL;
}

void UWorldMapDataComponent::UpdateAround(const FIntPoint& GridPosition, int32 OverrideRadius) {
}

void UWorldMapDataComponent::RevealFogOfWarMap() {
}

void UWorldMapDataComponent::QueueMapUpdateForNextTick(const TArray<FIntPoint>& Points) {
}

int32 UWorldMapDataComponent::GetMapTextureSize() {
    return 0;
}

UTexture2D* UWorldMapDataComponent::GetMapTexture_TerrainIDs() const {
    return NULL;
}

UTexture2D* UWorldMapDataComponent::GetMapTexture_TerrainColors() const {
    return NULL;
}

UTexture2D* UWorldMapDataComponent::GetMapTexture_Paths() const {
    return NULL;
}

UTexture2D* UWorldMapDataComponent::GetMapTexture_Paint() const {
    return NULL;
}

UTexture2D* UWorldMapDataComponent::GetMapTexture_Buildings() const {
    return NULL;
}


