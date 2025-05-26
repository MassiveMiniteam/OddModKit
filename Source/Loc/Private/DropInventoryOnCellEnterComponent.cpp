#include "DropInventoryOnCellEnterComponent.h"

UDropInventoryOnCellEnterComponent::UDropInventoryOnCellEnterComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BiomeTracker = NULL;
    this->PlayerPositionComponent = NULL;
    this->bPlayerIsInTaggedCell = false;
}

void UDropInventoryOnCellEnterComponent::Update() {
}

void UDropInventoryOnCellEnterComponent::OnPlayerPositionChanged(UPositionSimulationComponent* PositionComponent, FIntVector LastPosition) {
}

void UDropInventoryOnCellEnterComponent::OnPlayerExitTaggedCell() {
}

void UDropInventoryOnCellEnterComponent::OnPlayerEnterTaggedCell() {
}

void UDropInventoryOnCellEnterComponent::OnCellChanged(UBiomeTrackerSimulationComponent* Component, UBiomeCellInstance* CellInstance) {
}

void UDropInventoryOnCellEnterComponent::DropInventoryToLastCellPosition() {
}


