#include "WakeupActorsInRadiusSimulationComponent.h"

UWakeupActorsInRadiusSimulationComponent::UWakeupActorsInRadiusSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GridUnitRadius = 3;
}

void UWakeupActorsInRadiusSimulationComponent::OnGridPositionChanged(UPositionSimulationComponent* PositionSimulationComponent, FIntPoint LastGridPosition) {
}


