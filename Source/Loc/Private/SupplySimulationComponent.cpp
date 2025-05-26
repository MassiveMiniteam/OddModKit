#include "SupplySimulationComponent.h"

USupplySimulationComponent::USupplySimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PerceptionSimulationComponent = NULL;
    this->SimulationTimerComponent = NULL;
    this->SupplyInventory = NULL;
}

void USupplySimulationComponent::OnTimerFired(USimulationTimerComponent* InSimulationTimerComponent) {
}

void USupplySimulationComponent::OnSupplySuccessEvent_Implementation() {
}

void USupplySimulationComponent::OnSupplyFailEvent_Implementation() {
}

void USupplySimulationComponent::OnItemRemovedFromSupplyInventory(UItemConfig* Config, int32 Amount, UObject* Origin) {
}

void USupplySimulationComponent::OnItemAddedToSupplyInventory(UItemConfig* Config, int32 Amount, UObject* Origin) {
}

void USupplySimulationComponent::CanAffordStateChangedEvent_Implementation(bool bState) {
}


