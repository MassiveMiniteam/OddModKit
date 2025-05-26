#include "InventoryAutoFillComponent.h"

UInventoryAutoFillComponent::UInventoryAutoFillComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UInventoryAutoFillComponent::OnToInventoryItemRemoved(UItemConfig* Item, int32 Amount, UObject* Origin) {
}

void UInventoryAutoFillComponent::OnFromInventoryItemAdded(UItemConfig* Item, int32 Amount, UObject* Origin) {
}

void UInventoryAutoFillComponent::FillInventory() {
}


