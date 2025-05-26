#include "ConstructionAssemblyPresentationComponent.h"

UConstructionAssemblyPresentationComponent::UConstructionAssemblyPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UConstructionAssemblyPresentationComponent::OnItemsDroppedAfterDisassembly(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingPlayer, TArray<AGridObject*> Items) {
}


void UConstructionAssemblyPresentationComponent::OnDisassembleAfterReplace_Implementation(UConstructionAssemblySimulationComponent* Component) {
}

void UConstructionAssemblyPresentationComponent::OnAssemblyStartedEvent_Implementation(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingPlayer) {
}

void UConstructionAssemblyPresentationComponent::OnAssemblyDoneEvent_Implementation(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingPlayer) {
}

void UConstructionAssemblyPresentationComponent::OnAssemblyAfterReplace_Implementation(UConstructionAssemblySimulationComponent* Component) {
}

void UConstructionAssemblyPresentationComponent::OnAssemblyAfterMoving_Implementation(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingPlayer) {
}

void UConstructionAssemblyPresentationComponent::HandleDisassemblyPrediction_Implementation() {
}

void UConstructionAssemblyPresentationComponent::HandleAssemblyPredition_Implementation() {
}


