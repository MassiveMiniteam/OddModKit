#include "BiomeTrackerSimulationComponent.h"

UBiomeTrackerSimulationComponent::UBiomeTrackerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BiomeConfig = NULL;
    this->CellInstance = NULL;
}

void UBiomeTrackerSimulationComponent::OnGridPositionChanged(UPositionSimulationComponent* InPositionComponent, FIntVector LastPosition) {
}

FIntPoint UBiomeTrackerSimulationComponent::GetLastCellPosition() const {
    return FIntPoint{};
}

UBiomeCellInstance* UBiomeTrackerSimulationComponent::GetCurrentBiomeInstance() {
    return NULL;
}

UBiomeConfig* UBiomeTrackerSimulationComponent::GetCurrentBiomeConfig() {
    return NULL;
}


