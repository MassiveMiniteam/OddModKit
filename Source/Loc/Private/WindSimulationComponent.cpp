#include "WindSimulationComponent.h"

UWindSimulationComponent::UWindSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->bStartTickEnabled = false;
}

FIntPoint UWindSimulationComponent::GetCurrentWind() const {
    return FIntPoint{};
}

void UWindSimulationComponent::AddVelocity(FIntPoint Velocity) {
}

void UWindSimulationComponent::AddForce(FIntPoint Force) {
}


