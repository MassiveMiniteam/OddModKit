#include "PathFinderComponent.h"

UPathFinderComponent::UPathFinderComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->PathFindingRequest = NULL;
}

void UPathFinderComponent::SetTargetByObject(UPositionSimulationComponent* NewTargetPositionComponent) {
}

void UPathFinderComponent::SetTargetByCoordinates(const FIntVector& TargetCoordinates) {
}

void UPathFinderComponent::ResetAllProperties() {
}

void UPathFinderComponent::OnJumpCancelPathfinding(UProjectileSimulationComponent* ProjectileComponent, const FProjectileParameters& Parameters) {
}

bool UPathFinderComponent::IsCurrentlyCalculatingPath() const {
    return false;
}


