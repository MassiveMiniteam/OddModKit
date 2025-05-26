#include "ConnectToTrainInventorySimulationComponent.h"

UConnectToTrainInventorySimulationComponent::UConnectToTrainInventorySimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PoleComponent = NULL;
    this->InventoryConnectionTag = TEXT("TrainStationConnection");
    this->GameplayEffectOnAgentWhileConnected = NULL;
}

void UConnectToTrainInventorySimulationComponent::OnTrainAgentStopsMovement(const UTrainTracksPoleBaseSimulationComponent* Pole, const UTrainTracksAgentSimulationComponent* Agent) {
}

void UConnectToTrainInventorySimulationComponent::OnTrainAgentStartsMovement(const UTrainTracksPoleBaseSimulationComponent* Pole, const UTrainTracksAgentSimulationComponent* Agent) {
}

void UConnectToTrainInventorySimulationComponent::OnGameplayEffectRemoved() {
}


