#include "SubGridMovementSimulationComponent.h"

USubGridMovementSimulationComponent::USubGridMovementSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->NumSubGridPositions = 2;
}

bool USubGridMovementSimulationComponent::NextSubGridPositionMovesOutOfCurrentTile() const {
    return false;
}

FIntPoint USubGridMovementSimulationComponent::GetTargetGridPosition() const {
    return FIntPoint{};
}

int32 USubGridMovementSimulationComponent::GetNumSubGridPositions() const {
    return 0;
}

void USubGridMovementSimulationComponent::GetNextGridPositionAndSubGridPosition(FIntPoint& GridPosition, FIntPoint& SubGridPosition) const {
}

FIntPoint USubGridMovementSimulationComponent::GetLastHeading() const {
    return FIntPoint{};
}

FIntPoint USubGridMovementSimulationComponent::GetLastGridPosition() const {
    return FIntPoint{};
}

FFixed USubGridMovementSimulationComponent::GetDurationInSecondsPerSubTile() const {
    return FFixed{};
}

FFixed USubGridMovementSimulationComponent::GetCurrentSubGridProgress() const {
    return FFixed{};
}

FIntPoint USubGridMovementSimulationComponent::GetCurrentSubGridPosition() const {
    return FIntPoint{};
}

FIntPoint USubGridMovementSimulationComponent::GetCurrentSubGridHeading() const {
    return FIntPoint{};
}

FIntPoint USubGridMovementSimulationComponent::GetCurrentHeading() const {
    return FIntPoint{};
}

FIntPoint USubGridMovementSimulationComponent::GetCurrentGridPosition() const {
    return FIntPoint{};
}


