#include "DynamicInventoryRefSimulation.h"

UDynamicInventoryRefSimulation::UDynamicInventoryRefSimulation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TargetInventory = NULL;
}

void UDynamicInventoryRefSimulation::SetTargetInventory(UInventoryComponent* InventoryIn) {
}

UInventoryComponent* UDynamicInventoryRefSimulation::GetTargetInventory() const {
    return NULL;
}


