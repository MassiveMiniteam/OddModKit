#include "ProjectilePresentationComponent.h"

UProjectilePresentationComponent::UProjectilePresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bRotateToThrowDirection = true;
    this->bFullProjectileCurveRotation = false;
}


void UProjectilePresentationComponent::OnSimulationLaunched(UProjectileSimulationComponent* SimulationComponent, const FProjectileParameters& SimulationParameters) {
}

void UProjectilePresentationComponent::OnSimulationAtTarget(UProjectileSimulationComponent* SimulationComponent, const FProjectileParameters& SimulationParameters) {
}


void UProjectilePresentationComponent::LaunchPredicted(const FProjectileParameters& SimulationParameters) {
}

void UProjectilePresentationComponent::Launch(const FProjectileParameters& SimulationParameters, bool bIgnorePredictionAlreadyRunning) {
}

bool UProjectilePresentationComponent::IsRunning() const {
    return false;
}

bool UProjectilePresentationComponent::IsCurrentlyInPrediction() const {
    return false;
}

FVector UProjectilePresentationComponent::GetCurrentTargetPosition() const {
    return FVector{};
}

float UProjectilePresentationComponent::GetCurrentProgress() const {
    return 0.0f;
}

FProjectilePresentationParameters UProjectilePresentationComponent::GetCurrentParameters() const {
    return FProjectilePresentationParameters{};
}


