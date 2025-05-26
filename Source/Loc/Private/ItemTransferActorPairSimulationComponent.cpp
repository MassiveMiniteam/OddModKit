#include "ItemTransferActorPairSimulationComponent.h"

UItemTransferActorPairSimulationComponent::UItemTransferActorPairSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UItemTransferActorPairSimulationComponent::OnRelatedGridObjectConnected(UGridObjectPairSimulationComponent* Component, AGridObject* GridObject) {
}

void UItemTransferActorPairSimulationComponent::OnPairedSimulationActorShutdown(ASimulationActor* InSimulationActor, EDestructionReason Reason) {
}

void UItemTransferActorPairSimulationComponent::OnPairedActorDisassemble(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer) {
}

void UItemTransferActorPairSimulationComponent::OnDisassemble(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer) {
}


