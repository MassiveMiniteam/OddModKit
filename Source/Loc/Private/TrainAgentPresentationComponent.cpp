#include "TrainAgentPresentationComponent.h"

UTrainAgentPresentationComponent::UTrainAgentPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->WheelRotationAnglePerCentiMeterTravelled = 0.00f;
    this->AudioComponent = NULL;
}

void UTrainAgentPresentationComponent::OnSimulationMovementStopped(UTrainTracksAgentSimulationComponent* Agent) {
}

void UTrainAgentPresentationComponent::OnSimulationMovementStarted(UTrainTracksAgentSimulationComponent* Agent) {
}


