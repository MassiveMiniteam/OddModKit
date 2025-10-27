#include "BalloonCarrySimulationComponent.h"

UBalloonCarrySimulationComponent::UBalloonCarrySimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StatsComponent = NULL;
    this->bIsCarryingBalloon = false;
}

FBalloonConfig UBalloonCarrySimulationComponent::GetBalloonConfig() const {
    return FBalloonConfig{};
}


