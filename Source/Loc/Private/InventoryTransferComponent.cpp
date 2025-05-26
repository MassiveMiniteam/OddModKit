#include "InventoryTransferComponent.h"

UInventoryTransferComponent::UInventoryTransferComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SourceInventory = NULL;
    this->TargetInventory = NULL;
}

void UInventoryTransferComponent::OnItemAdded(UItemConfig* Config, int32 Amount, UObject* Origin) {
}


