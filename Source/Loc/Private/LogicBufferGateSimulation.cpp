#include "LogicBufferGateSimulation.h"

ULogicBufferGateSimulation::ULogicBufferGateSimulation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void ULogicBufferGateSimulation::SetBufferTargetTime(FFixed NewBufferTime) {
}

void ULogicBufferGateSimulation::OnInputSignalChanged(ULogicConnectionSimulationComponent* Input) {
}

FFixed ULogicBufferGateSimulation::GetCurrentBufferTime() {
    return FFixed{};
}

FFixed ULogicBufferGateSimulation::GetBufferTargetTime() {
    return FFixed{};
}


