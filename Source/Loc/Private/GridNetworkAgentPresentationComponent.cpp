#include "GridNetworkAgentPresentationComponent.h"

UGridNetworkAgentPresentationComponent::UGridNetworkAgentPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseAggregatedTick = true;
    this->OrthogonalOffset = 15.00f;
    this->RotationSpeed = 10.00f;
    this->bAllowPitchRotation = false;
}

void UGridNetworkAgentPresentationComponent::OnSimulationSubGridPositionChanged(USubGridMovementSimulationComponent* Component) {
}


