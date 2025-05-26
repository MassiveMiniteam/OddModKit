#include "TrainTrackSegmentSimulationComponent.h"

UTrainTrackSegmentSimulationComponent::UTrainTrackSegmentSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UTrainTrackSegmentSimulationComponent::UpdateCachedSpline() {
}

void UTrainTrackSegmentSimulationComponent::RemoveConnections() {
}

bool UTrainTrackSegmentSimulationComponent::IsOccupied() const {
    return false;
}

bool UTrainTrackSegmentSimulationComponent::IsConnectedTo(const UTrainTracksPoleBaseSimulationComponent* Pole) const {
    return false;
}

FFixed64 UTrainTrackSegmentSimulationComponent::GetLength() const {
    return FFixed64{};
}

UTrainTracksPoleConnectionSimulationComponent* UTrainTrackSegmentSimulationComponent::GetConnectedPoleStart() const {
    return NULL;
}

UTrainTracksPoleConnectionSimulationComponent* UTrainTrackSegmentSimulationComponent::GetConnectedPoleEnd() const {
    return NULL;
}

FFixed64Spline UTrainTrackSegmentSimulationComponent::GetCachedTrackSpline() const {
    return FFixed64Spline{};
}

TArray<UTrainTracksAgentSimulationComponent*> UTrainTrackSegmentSimulationComponent::GetAgentsOnThisSegment() const {
    return TArray<UTrainTracksAgentSimulationComponent*>();
}

void UTrainTrackSegmentSimulationComponent::ConnectTo(UTrainTracksPoleConnectionSimulationComponent* Connection) {
}


