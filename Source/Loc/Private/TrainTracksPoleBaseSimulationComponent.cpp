#include "TrainTracksPoleBaseSimulationComponent.h"

UTrainTracksPoleBaseSimulationComponent::UTrainTracksPoleBaseSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UTrainTracksPoleBaseSimulationComponent::SetPositionOffset(FIntVector NewPositionOffset) {
}

bool UTrainTracksPoleBaseSimulationComponent::IsTrainStopControlledByLogic() const {
    return false;
}

bool UTrainTracksPoleBaseSimulationComponent::IsConnectedTo(const UTrainTrackSegmentSimulationComponent* Segment) const {
    return false;
}

bool UTrainTracksPoleBaseSimulationComponent::HasUsableConnection() const {
    return false;
}

bool UTrainTracksPoleBaseSimulationComponent::HasLogicInputSignal() const {
    return false;
}

bool UTrainTracksPoleBaseSimulationComponent::HasConnectedConnectionsWithTag(FName Tag) const {
    return false;
}

FIntVector UTrainTracksPoleBaseSimulationComponent::GetPositionOffset() const {
    return FIntVector{};
}

UTrainTrackSegmentSimulationComponent* UTrainTracksPoleBaseSimulationComponent::GetNextTrackSegment(const UTrainTracksAgentSimulationComponent* Agent, const UTrainTrackSegmentSimulationComponent* LastSegment) const {
    return NULL;
}

TArray<UTrainTracksPoleConnectionSimulationComponent*> UTrainTracksPoleBaseSimulationComponent::GetConnectedConnectionsWithTag(FName Tag) const {
    return TArray<UTrainTracksPoleConnectionSimulationComponent*>();
}

TArray<UTrainTracksPoleConnectionSimulationComponent*> UTrainTracksPoleBaseSimulationComponent::GetConnectedConnections() const {
    return TArray<UTrainTracksPoleConnectionSimulationComponent*>();
}

UTrainTracksPoleConnectionSimulationComponent* UTrainTracksPoleBaseSimulationComponent::GetClosestUsableConnection(const FIntVector& QueryLocation) const {
    return NULL;
}

TArray<UTrainTracksPoleConnectionSimulationComponent*> UTrainTracksPoleBaseSimulationComponent::GetAllConnections() const {
    return TArray<UTrainTracksPoleConnectionSimulationComponent*>();
}

UTrainTrackSegmentSimulationComponent* UTrainTracksPoleBaseSimulationComponent::FindSegmentByOtherPole(const UTrainTracksPoleBaseSimulationComponent* OtherPole) const {
    return NULL;
}

UTrainTracksPoleConnectionSimulationComponent* UTrainTracksPoleBaseSimulationComponent::FindConnectionBySegment(const UTrainTrackSegmentSimulationComponent* Segment) const {
    return NULL;
}


