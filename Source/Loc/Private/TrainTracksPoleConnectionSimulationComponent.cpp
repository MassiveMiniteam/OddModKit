#include "TrainTracksPoleConnectionSimulationComponent.h"

UTrainTracksPoleConnectionSimulationComponent::UTrainTracksPoleConnectionSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CachedOwnerPole = NULL;
    this->MyAssemblyComponent = NULL;
}

void UTrainTracksPoleConnectionSimulationComponent::SetConnection(UTrainTrackSegmentSimulationComponent* Segment) {
}

void UTrainTracksPoleConnectionSimulationComponent::OnDisassmble(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer) {
}

bool UTrainTracksPoleConnectionSimulationComponent::IsConnected() const {
    return false;
}

UTrainTracksPoleBaseSimulationComponent* UTrainTracksPoleConnectionSimulationComponent::GetPoleComponent() const {
    return NULL;
}

FIntVector UTrainTracksPoleConnectionSimulationComponent::GetPoleCenterTangent() const {
    return FIntVector{};
}

FIntVector UTrainTracksPoleConnectionSimulationComponent::GetOuterSplinePointTangent() const {
    return FIntVector{};
}

FIntVector UTrainTracksPoleConnectionSimulationComponent::GetOuterSplinePointOffset() const {
    return FIntVector{};
}

UTrainTrackSegmentSimulationComponent* UTrainTracksPoleConnectionSimulationComponent::GetConnectedSegment() const {
    return NULL;
}

USceneComponent* UTrainTracksPoleConnectionSimulationComponent::GetAttachmentScene_PoleCenter() const {
    return NULL;
}

USceneComponent* UTrainTracksPoleConnectionSimulationComponent::GetAttachmentScene_OuterSplinePoint() const {
    return NULL;
}

bool UTrainTracksPoleConnectionSimulationComponent::CanBeConnected() const {
    return false;
}


