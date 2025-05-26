#include "CellLoaderSimulationComponent.h"

UCellLoaderSimulationComponent::UCellLoaderSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RadiusInGridUnits = 50;
    this->SampleAngle = 45;
}

void UCellLoaderSimulationComponent::OnGridPositionChanged(UPositionSimulationComponent* PositionSimulationComponent, FIntPoint LastGridPosition) {
}


