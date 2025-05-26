#include "CarrySimulationComponent.h"

UCarrySimulationComponent::UCarrySimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StatsComponent = NULL;
    this->InventoryComponent = NULL;
}

void UCarrySimulationComponent::TryPickupGridObjectAt(FIntPoint position) {
}

bool UCarrySimulationComponent::TryAddToInventory(UInventoryComponent* Inventory) {
    return false;
}

bool UCarrySimulationComponent::IsCarryingItem() const {
    return false;
}

bool UCarrySimulationComponent::HasCarryingCapacity() const {
    return false;
}

int32 UCarrySimulationComponent::GetRemainingCapacity() const {
    return 0;
}

FFixed UCarrySimulationComponent::GetPickupDelay() const {
    return FFixed{};
}

TArray<UItemConfig*> UCarrySimulationComponent::GetItemPickUpWhiteList() const {
    return TArray<UItemConfig*>();
}

UItemConfig* UCarrySimulationComponent::GetCarryItemConfig() const {
    return NULL;
}

FItemStack UCarrySimulationComponent::GetCarriedItemStack() const {
    return FItemStack{};
}

int32 UCarrySimulationComponent::GetCarriedItemAmount() const {
    return 0;
}

void UCarrySimulationComponent::DropCarriedItem() {
}


