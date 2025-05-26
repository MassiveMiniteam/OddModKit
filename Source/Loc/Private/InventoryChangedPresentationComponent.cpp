#include "InventoryChangedPresentationComponent.h"

UInventoryChangedPresentationComponent::UInventoryChangedPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UInventoryChangedPresentationComponent::Unbind() {
}

void UInventoryChangedPresentationComponent::SetAndBindInventory(UInventoryComponent* InInventory) {
}

void UInventoryChangedPresentationComponent::OnInventoryItemRemoved_Implementation(UItemConfig* Config, int32 Amount, UObject* Origin) {
}

void UInventoryChangedPresentationComponent::OnInventoryItemAdded_Implementation(UItemConfig* Config, int32 Amount, UObject* Origin) {
}


