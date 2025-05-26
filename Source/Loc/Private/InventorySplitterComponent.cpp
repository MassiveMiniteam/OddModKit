#include "InventorySplitterComponent.h"

UInventorySplitterComponent::UInventorySplitterComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InputInventory = NULL;
    this->InventoryIndex = 0;
}


