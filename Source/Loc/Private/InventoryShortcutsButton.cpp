#include "InventoryShortcutsButton.h"

UInventoryShortcutsButton::UInventoryShortcutsButton() {
    this->SourceInventory = NULL;
    this->TargetInventory = NULL;
    this->bShowTooltipLeft = false;
    this->SuccessSound = NULL;
    this->FailSound = NULL;
}

void UInventoryShortcutsButton::UpdateEnableState_Implementation() {
}

void UInventoryShortcutsButton::SetInventories(UInventoryComponent* InSourceInventory, UInventoryComponent* InTargetInventory) {
}

void UInventoryShortcutsButton::PlaySuccessSound() {
}

void UInventoryShortcutsButton::PlayFailSound() {
}

bool UInventoryShortcutsButton::IsTargetInventoryEmpty() {
    return false;
}

bool UInventoryShortcutsButton::IsSourceInventoryEmpty() {
    return false;
}

bool UInventoryShortcutsButton::DoesTargetInventoryContainAnyItemOfSourceInventory() {
    return false;
}

bool UInventoryShortcutsButton::CanAddAnyItemToTargetInventory() {
    return false;
}


