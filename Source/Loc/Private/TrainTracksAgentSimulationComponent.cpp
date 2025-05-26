#include "TrainTracksAgentSimulationComponent.h"

UTrainTracksAgentSimulationComponent::UTrainTracksAgentSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->bWasMovingLastFrame = true;
    this->PositionComponent = NULL;
    this->ActorChainComponent = NULL;
}

bool UTrainTracksAgentSimulationComponent::WholeTrainHasAnyLocomotive() const {
    return false;
}

void UTrainTracksAgentSimulationComponent::UpdateAllTrainAgentPositionsStartingOnPrimaryAgent() {
}

bool UTrainTracksAgentSimulationComponent::IsPlacedOnTracks() const {
    return false;
}

bool UTrainTracksAgentSimulationComponent::IsLeadingLocomotive() const {
    return false;
}

bool UTrainTracksAgentSimulationComponent::IsCurrentlyMoving() const {
    return false;
}

bool UTrainTracksAgentSimulationComponent::HasCurrentlyPlayerInput() const {
    return false;
}

FTrainTrackLocation UTrainTracksAgentSimulationComponent::GetTrackLocation() const {
    return FTrainTrackLocation{};
}

UTrainTracksAgentSimulationComponent* UTrainTracksAgentSimulationComponent::GetPrimaryAgent() const {
    return NULL;
}

UTrainTracksPoleBaseSimulationComponent* UTrainTracksAgentSimulationComponent::GetPreviousPole() const {
    return NULL;
}

UTrainTracksAgentSimulationComponent* UTrainTracksAgentSimulationComponent::GetPreviousAgent() const {
    return NULL;
}

UTrainTracksPoleBaseSimulationComponent* UTrainTracksAgentSimulationComponent::GetNextPole() const {
    return NULL;
}

UTrainTracksAgentSimulationComponent* UTrainTracksAgentSimulationComponent::GetNextAgent() const {
    return NULL;
}

FTrainTrackLocation UTrainTracksAgentSimulationComponent::GetLastLocation() const {
    return FTrainTrackLocation{};
}

UTrainTracksAgentSimulationComponent* UTrainTracksAgentSimulationComponent::GetLastAttachedAgent() const {
    return NULL;
}

UTrainTracksAgentSimulationComponent* UTrainTracksAgentSimulationComponent::GetFrontAgent() const {
    return NULL;
}

UTrainTrackSegmentSimulationComponent* UTrainTracksAgentSimulationComponent::GetCurrentSegment() const {
    return NULL;
}

FFixed64 UTrainTracksAgentSimulationComponent::GetCurrentProgressOnSegment() const {
    return FFixed64{};
}

FFixed64 UTrainTracksAgentSimulationComponent::GetCurrentMovementDelta() const {
    return FFixed64{};
}

FFixed64 UTrainTracksAgentSimulationComponent::GetCurrentDistanceAlongSegment() const {
    return FFixed64{};
}

UTrainTracksPoleBaseSimulationComponent* UTrainTracksAgentSimulationComponent::GetClosestPole() const {
    return NULL;
}

void UTrainTracksAgentSimulationComponent::AttachInFrontOfTrainAgent(UTrainTracksAgentSimulationComponent* TrainAgent) {
}

void UTrainTracksAgentSimulationComponent::AttachBehindTrainAgent(UTrainTracksAgentSimulationComponent* TrainAgent) {
}


