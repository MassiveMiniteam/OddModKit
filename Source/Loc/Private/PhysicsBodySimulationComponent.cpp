#include "PhysicsBodySimulationComponent.h"

UPhysicsBodySimulationComponent::UPhysicsBodySimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->bBlockPositionUpdate = false;
    this->RammedIntoWallOrObjectGameplayEffect = NULL;
    this->MinSpeedForTriggeringCollision = 100;
    this->bTestCollisionOnEdgeOfRadius = false;
}

FIntVector UPhysicsBodySimulationComponent::GetCurrentVelocity() const {
    return FIntVector{};
}

void UPhysicsBodySimulationComponent::AddVelocity(FIntVector Velocity) {
}

void UPhysicsBodySimulationComponent::AddForceDirectionAndScale(FIntVector ForceDirection, int32 ForceScale) {
}

void UPhysicsBodySimulationComponent::AddForce(FIntVector Force) {
}


