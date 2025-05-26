#include "LocomotiveSimulationComponent.h"

ULocomotiveSimulationComponent::ULocomotiveSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->StatsComponent = NULL;
    this->WorkerInventory = NULL;
    this->PlayerInputComponent = NULL;
    this->FuelDecayComponent = NULL;
    this->TrainAgentComponent = NULL;
}

bool ULocomotiveSimulationComponent::WantsToDriveForward() const {
    return false;
}

bool ULocomotiveSimulationComponent::WantsToDriveBackward() const {
    return false;
}

void ULocomotiveSimulationComponent::OnMovementStopped(UTrainTracksAgentSimulationComponent* Agent) {
}

void ULocomotiveSimulationComponent::OnMovementStarted(UTrainTracksAgentSimulationComponent* Agent) {
}

bool ULocomotiveSimulationComponent::HasPlayerInput() const {
    return false;
}

bool ULocomotiveSimulationComponent::HasMovementBlockedStat() const {
    return false;
}

bool ULocomotiveSimulationComponent::HasFuel() const {
    return false;
}

FFixed64 ULocomotiveSimulationComponent::GetCurrentMovementSpeed() const {
    return FFixed64{};
}


