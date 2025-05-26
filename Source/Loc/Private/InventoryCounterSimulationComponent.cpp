#include "InventoryCounterSimulationComponent.h"

UInventoryCounterSimulationComponent::UInventoryCounterSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InventoryComponent = NULL;
}

void UInventoryCounterSimulationComponent::OnInventorySlotChanged(int32 SlotIndex) {
}

void UInventoryCounterSimulationComponent::IterateSlotIndex(int32 SlotIndex) {
}

int32 UInventoryCounterSimulationComponent::GetCounterForIndex(int32 Index) const {
    return 0;
}


