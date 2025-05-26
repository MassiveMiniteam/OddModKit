#include "ConstructionAssemblySimulationComponent.h"

UConstructionAssemblySimulationComponent::UConstructionAssemblySimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->bStartTickEnabled = false;
    this->SpawnOrderIndex = 0;
    this->bDisassembleOverlappingPathsOnDisassemble = false;
    this->ConstructableConfig = NULL;
    this->bIsRelocating = false;
    this->bResetTickingAfterFinish = false;
    this->SimulationPlayer = NULL;
}

void UConstructionAssemblySimulationComponent::StartAssemblyAfterReplace() {
}

void UConstructionAssemblySimulationComponent::StartAssemblyAfterMoving(ASimulationPlayer* ExecutingSimulationPlayer) {
}

void UConstructionAssemblySimulationComponent::StartAssembly(ASimulationPlayer* ExecutingSimulationPlayer) {
}

void UConstructionAssemblySimulationComponent::SetRelocateState(bool bInIsRelocating, ASimulationPlayer* ExecutingSimulationPlayer) {
}

void UConstructionAssemblySimulationComponent::OnRelocateStartEvent_Implementation(ASimulationPlayer* ExecutingSimulationPlayer) {
}

void UConstructionAssemblySimulationComponent::OnRelocateEndEvent_Implementation(ASimulationPlayer* ExecutingSimulationPlayer) {
}

bool UConstructionAssemblySimulationComponent::IsDisassemblyAllowed() {
    return false;
}

UConstructableConfig* UConstructionAssemblySimulationComponent::GetConstructableConfig() const {
    return NULL;
}

void UConstructionAssemblySimulationComponent::DisassembleFromReplace() {
}

void UConstructionAssemblySimulationComponent::Disassemble(ASimulationPlayer* ExecutingSimulationPlayer) {
}


