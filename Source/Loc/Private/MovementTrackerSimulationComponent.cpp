#include "MovementTrackerSimulationComponent.h"

UMovementTrackerSimulationComponent::UMovementTrackerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->NumMaxTrackedPositions = 10;
    this->DistanceBetweenTrackedPoints = 100;
    this->ProjectTrackedPositionsOntoLandscape = true;
}

void UMovementTrackerSimulationComponent::OnPositionChanged(UPositionSimulationComponent* InPositionComponent, FIntVector LastPosition) {
}

TArray<FIntVector> UMovementTrackerSimulationComponent::GetTrackedPath() const {
    return TArray<FIntVector>();
}

FIntVector UMovementTrackerSimulationComponent::GetPositionAlongTrack(int32 DistanceFromLastTrackedPoint) const {
    return FIntVector{};
}

FFixedVector UMovementTrackerSimulationComponent::GetNormalizedNormalAlongTrack(int32 DistanceFromLastTrackedPoint) const {
    return FFixedVector{};
}


