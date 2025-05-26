#include "ProjectileSimulationComponent.h"

UProjectileSimulationComponent::UProjectileSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bSetOwnerPositionToDestinationOnLaunch = false;
}

void UProjectileSimulationComponent::Launch(const FProjectileParameters& Parameters) {
}

FIntVector UProjectileSimulationComponent::GetTargetPosition() const {
    return FIntVector{};
}

bool UProjectileSimulationComponent::GetIsMidAir() const {
    return false;
}

FProjectileParameters UProjectileSimulationComponent::GetCurrentParameters() const {
    return FProjectileParameters{};
}


