#include "TrainTrackSegmentSimulationComponent.h"

UTrainTrackSegmentSimulationComponent::UTrainTrackSegmentSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bTrainIgnoresSlope = false;
    this->FixedAmountOfSegments = -1;
}

void UTrainTrackSegmentSimulationComponent::UpdateCachedSpline() {
}

void UTrainTrackSegmentSimulationComponent::SetTrainIgnoresSlope(bool bIgnoreSlope) {
}

void UTrainTrackSegmentSimulationComponent::SetOverwriteSpline(const TArray<FFixed64SplinePoint>& SplinePoints) {
}

void UTrainTrackSegmentSimulationComponent::SetFixedAmountOfSegments(int32 Amount) {
}

void UTrainTrackSegmentSimulationComponent::RemoveConnections() {
}

bool UTrainTrackSegmentSimulationComponent::IsOccupied() const {
    return false;
}

bool UTrainTrackSegmentSimulationComponent::IsConnectedTo(const UTrainTracksPoleBaseSimulationComponent* Pole) const {
    return false;
}

bool UTrainTrackSegmentSimulationComponent::GetTrainIgnoresSlope() const {
    return false;
}

FFixed64 UTrainTrackSegmentSimulationComponent::GetLength() const {
    return FFixed64{};
}

int32 UTrainTrackSegmentSimulationComponent::GetFixedAmountOfSegments() const {
    return 0;
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


