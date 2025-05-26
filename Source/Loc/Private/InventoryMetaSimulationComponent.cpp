#include "InventoryMetaSimulationComponent.h"

UInventoryMetaSimulationComponent::UInventoryMetaSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TargetInventory = NULL;
}

void UInventoryMetaSimulationComponent::OnInventorySlotChanged(int32 SlotIndex) {
}

bool UInventoryMetaSimulationComponent::IsRefillFromInventoryPossible(UInventoryComponent* ProviderInventory) {
    return false;
}

UInventoryComponent* UInventoryMetaSimulationComponent::GetTargetInventory() const {
    return NULL;
}

FInventorySlotMeta UInventoryMetaSimulationComponent::GetMetaForSlot(int32 Slot) {
    return FInventorySlotMeta{};
}

void UInventoryMetaSimulationComponent::ClearMetaForSlot(int32 Slot) {
}


