#include "UnitMovementPresentationComponent.h"

UUnitMovementPresentationComponent::UUnitMovementPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseAggregatedTick = true;
    this->RotationLerpSpeed = 0.10f;
}

void UUnitMovementPresentationComponent::OnTeleported_Implementation(UUnitMovementSimulationComponent* MovementSimulationComponent, FIntVector FromPosition, FIntVector ToPosition) {
}


