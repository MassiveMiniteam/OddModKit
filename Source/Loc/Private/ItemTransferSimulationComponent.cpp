#include "ItemTransferSimulationComponent.h"

UItemTransferSimulationComponent::UItemTransferSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UItemTransferSimulationComponent::SetTargetInventory(UInventoryComponent* Inventory) {
}

void UItemTransferSimulationComponent::SetItemTransferDuration(FFixed NewDuration) {
}

FFixed UItemTransferSimulationComponent::GetItemTransferDuration() const {
    return FFixed{};
}

FFixed UItemTransferSimulationComponent::GetItemStartInterval() const {
    return FFixed{};
}

TArray<FItemStack> UItemTransferSimulationComponent::GetAllCurrentlyTransportedItems() {
    return TArray<FItemStack>();
}


