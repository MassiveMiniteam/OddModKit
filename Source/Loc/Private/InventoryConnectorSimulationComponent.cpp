#include "InventoryConnectorSimulationComponent.h"

UInventoryConnectorSimulationComponent::UInventoryConnectorSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ConnectionData.AddDefaulted(1);
}

void UInventoryConnectorSimulationComponent::OnDynamicInventoryTargetChanged(UDynamicInventoryRefSimulation* Component, UInventoryComponent* NewInventory) {
}

UInventoryComponent* UInventoryConnectorSimulationComponent::GetInventory() const {
    return NULL;
}

TArray<FIntPoint> UInventoryConnectorSimulationComponent::GetInteractionTiles(bool Inputs) const {
    return TArray<FIntPoint>();
}


