#include "LocomotiveSimulationComponent.h"

ULocomotiveSimulationComponent::ULocomotiveSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->StatsComponent = NULL;
    this->WorkerInventory = NULL;
    this->PlayerInputComponent = NULL;
    this->TrainAgentComponent = NULL;
    this->Strategy = NULL;
}

bool ULocomotiveSimulationComponent::WantsToDriveForward() const {
    return false;
}

bool ULocomotiveSimulationComponent::WantsToDriveBackward() const {
    return false;
}

bool ULocomotiveSimulationComponent::HasPlayerInput() const {
    return false;
}

bool ULocomotiveSimulationComponent::HasMovementBlockedStat() const {
    return false;
}

FFixed64 ULocomotiveSimulationComponent::GetCurrentMovementSpeed() const {
    return FFixed64{};
}


