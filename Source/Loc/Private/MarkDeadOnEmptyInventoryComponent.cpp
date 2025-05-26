#include "MarkDeadOnEmptyInventoryComponent.h"

UMarkDeadOnEmptyInventoryComponent::UMarkDeadOnEmptyInventoryComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UMarkDeadOnEmptyInventoryComponent::OnInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item) {
}


