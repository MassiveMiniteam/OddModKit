#include "LogicCounterGateSimulation.h"

ULogicCounterGateSimulation::ULogicCounterGateSimulation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Counter = 0;
    this->TargetValue = 10;
    this->bLastInputValue = false;
    this->bFlipDisplay = false;
    this->LogicInput = NULL;
    this->LogicReset = NULL;
    this->LogicOutput = NULL;
}

void ULogicCounterGateSimulation::SetTarget(int32 TargetIn) {
}

void ULogicCounterGateSimulation::SetDisplayFlipped(bool FlipDisplay) {
}

void ULogicCounterGateSimulation::SetCounter(int32 CounterIn) {
}

void ULogicCounterGateSimulation::OnResetSignalChanged(ULogicConnectionSimulationComponent* Input) {
}

void ULogicCounterGateSimulation::OnInputSignalChanged(ULogicConnectionSimulationComponent* Input) {
}

bool ULogicCounterGateSimulation::IsDisplayFlipped() const {
    return false;
}

int32 ULogicCounterGateSimulation::GetTargetValue() const {
    return 0;
}

int32 ULogicCounterGateSimulation::GetCounterValue() const {
    return 0;
}


