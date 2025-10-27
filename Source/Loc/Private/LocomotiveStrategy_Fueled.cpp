#include "LocomotiveStrategy_Fueled.h"

ULocomotiveStrategy_Fueled::ULocomotiveStrategy_Fueled() {
    this->FuelDecayComponent = NULL;
}

void ULocomotiveStrategy_Fueled::OnMovementStopped(UTrainTracksAgentSimulationComponent* Agent) {
}

void ULocomotiveStrategy_Fueled::OnMovementStarted(UTrainTracksAgentSimulationComponent* Agent) {
}


