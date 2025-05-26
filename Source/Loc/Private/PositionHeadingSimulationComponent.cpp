#include "PositionHeadingSimulationComponent.h"

UPositionHeadingSimulationComponent::UPositionHeadingSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
}

FFixed UPositionHeadingSimulationComponent::GetSpeedInSecondsPerTile() const {
    return FFixed{};
}

EHeadingComponentTurnTypes UPositionHeadingSimulationComponent::GetCurrentTurnType() const {
    return EHeadingComponentTurnTypes::Straight;
}

FFixed UPositionHeadingSimulationComponent::GetCurrentTileProgress() const {
    return FFixed{};
}


