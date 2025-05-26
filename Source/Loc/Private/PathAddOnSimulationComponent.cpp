#include "PathAddOnSimulationComponent.h"

UPathAddOnSimulationComponent::UPathAddOnSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UPathAddOnSimulationComponent::OnRelocated(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer) {
}

void UPathAddOnSimulationComponent::OnPathBelowDisassemble(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer) {
}

void UPathAddOnSimulationComponent::OnLogicSignalChanged(ULogicConnectionSimulationComponent* Input) {
}

void UPathAddOnSimulationComponent::OnGridCellChanged(FIntPoint GridPosition) {
}

bool UPathAddOnSimulationComponent::IsAddOnActive() const {
    return false;
}

bool UPathAddOnSimulationComponent::AgentShouldWaitBeforeEntering(const UGridNetworkAgentSimulationComponent* Agent, FIntPoint HeadingIntoThisTile) const {
    return false;
}


