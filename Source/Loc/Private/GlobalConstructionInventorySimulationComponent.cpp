#include "GlobalConstructionInventorySimulationComponent.h"

UGlobalConstructionInventorySimulationComponent::UGlobalConstructionInventorySimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

UInventoryComponent* UGlobalConstructionInventorySimulationComponent::GetLinkedInventory() const {
    return NULL;
}


