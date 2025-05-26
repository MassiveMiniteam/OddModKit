#include "FloatingMovementPresentationComponent.h"

UFloatingMovementPresentationComponent::UFloatingMovementPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MaxSpeed = 100.00f;
    this->Acceleration = 100.00f;
    this->Friction = 100.00f;
    this->RotateTowardsAcceleration = true;
    this->RotationSpeed = 0.10f;
}

void UFloatingMovementPresentationComponent::FlipVelocityOnWall(FVector WallNormal, float VelocityFactor) {
}

void UFloatingMovementPresentationComponent::Accelerate(FVector Direction) {
}


