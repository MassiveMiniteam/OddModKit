#include "ProceduralTerrainManager.h"

AProceduralTerrainManager::AProceduralTerrainManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RampLayer = NULL;
    this->LakeLayer = NULL;
    this->GridTileRules = NULL;
    this->GridTileRulesDiggables = NULL;
    this->TileMeshRenderer = NULL;
    this->CurrentLoadStrategy = NULL;
    this->CurrentPhysicsLoadStrategy = NULL;
    this->VillageLoadStrategy = NULL;
    this->VillagePhysicsLoadStrategy = NULL;
    this->LoadStrategy_AroundLocalPlayer = NULL;
    this->LoadStrategy_AroundLocalPlayer_Physics = NULL;
}

void AProceduralTerrainManager::OnGridCellMeshNeedsUpdate(FIntPoint GridPos, bool bIsHeightChange) {
}


