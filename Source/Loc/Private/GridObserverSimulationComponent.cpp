#include "GridObserverSimulationComponent.h"

UGridObserverSimulationComponent::UGridObserverSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PositionComponent = NULL;
}

void UGridObserverSimulationComponent::OnRelocated(UPositionSimulationComponent* PositionSimulationComponent, FIntVector LastPosition) {
}


TArray<FIntPoint> UGridObserverSimulationComponent::GetTargetCells() const {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> UGridObserverSimulationComponent::GetStoredRelativeTargetCells() const {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> UGridObserverSimulationComponent::GetRelativeTargetCells_Implementation() {
    return TArray<FIntPoint>();
}

TArray<FIntPoint> UGridObserverSimulationComponent::ConvertCellsToPositionAndRotation(FIntPoint GridPos, int32 Rotation, const TArray<FIntPoint>& CellsToConvert) const {
    return TArray<FIntPoint>();
}


