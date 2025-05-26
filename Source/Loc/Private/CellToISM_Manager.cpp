#include "CellToISM_Manager.h"

ACellToISM_Manager::ACellToISM_Manager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LoadSize = 64;
    this->DistanceForUpdate = 25;
    this->CurrentLoadStrategy = NULL;
    this->LoadStrategy_AroundLocalPlayer = NULL;
    this->bIsFirstTick = true;
}

void ACellToISM_Manager::UpdateTileAt(FIntPoint GridPosition) {
}

void ACellToISM_Manager::UpdateMeshes(bool bClear) {
}

void ACellToISM_Manager::RemoveMeshAtGridPosition(FIntPoint GridPosition) {
}

void ACellToISM_Manager::RemoveAll() {
}

void ACellToISM_Manager::OnGridCellMeshNeedsUpdate(FIntPoint GridPosition, bool bIsHeightChange) {
}

bool ACellToISM_Manager::IsDrawConditionMet_Implementation(FIntPoint GridPosition) {
    return false;
}

bool ACellToISM_Manager::HasISMForValue(int32 ValueToCheck, FIntPoint GridPosition) {
    return false;
}

int32 ACellToISM_Manager::GetValue_Implementation(FIntPoint GridPosition) {
    return 0;
}

int32 ACellToISM_Manager::GetNumCustomDataFloats_Implementation() const {
    return 0;
}

float ACellToISM_Manager::GetCustomDataFloat_Implementation(int32 CustomDataIndex, FIntPoint GridPosition) const {
    return 0.0f;
}


