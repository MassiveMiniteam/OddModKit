#include "GroundTileTransitionManager.h"

AGroundTileTransitionManager::AGroundTileTransitionManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LoadSize = 64;
    this->DistanceForUpdate = 25;
    this->CurrentLoadStrategy = NULL;
    this->LoadStrategy_AroundLocalPlayer = NULL;
    this->TransitionMesh = NULL;
    this->LakeLandscapeLayer = NULL;
    this->bIsFirstTick = true;
    this->Directions.AddDefaulted(4);
}

void AGroundTileTransitionManager::OnGridCellMeshNeedsUpdate(FIntPoint GridPosition, bool bIsHeightChange) {
}

void AGroundTileTransitionManager::ForceLoad() {
}


