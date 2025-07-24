#include "LogicFilterGateSimulation.h"

ULogicFilterGateSimulation::ULogicFilterGateSimulation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LogicInput = NULL;
    this->LogicOutput = NULL;
    this->LastTick = 0;
}

void ULogicFilterGateSimulation::SetFilterTargetTime(FFixed TagetTime) {
}

void ULogicFilterGateSimulation::OnInputSignalChanged(ULogicConnectionSimulationComponent* Input) {
}

FFixed ULogicFilterGateSimulation::GetFilterTargetTime() {
    return FFixed{};
}

FFixed ULogicFilterGateSimulation::GetCurrentFilterTime() {
    return FFixed{};
}


