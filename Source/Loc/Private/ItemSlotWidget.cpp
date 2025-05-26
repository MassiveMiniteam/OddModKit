#include "ItemSlotWidget.h"

UItemSlotWidget::UItemSlotWidget() {
    this->Inventory = NULL;
    this->VisualInventory = NULL;
    this->SlotIndex = 0;
    this->bIsSetup = false;
    this->bIgnoreInInventoryHolder = false;
    this->bIsPrediction = false;
    this->bAllowInteraction = true;
    this->bBlockTakeInteraction = false;
    this->TransferPriority = 0;
    this->InteractionData = NULL;
}

void UItemSlotWidget::UpdateHoldInteractions() {
}

void UItemSlotWidget::SlateHandleUnhovered() {
}

void UItemSlotWidget::SlateHandleHovered() {
}

void UItemSlotWidget::SlateHandleClicked() {
}

void UItemSlotWidget::Setup(UInventoryComponent* TargetInventory, int32 TargetSlotIndex, bool bInIsPrediction) {
}

void UItemSlotWidget::PickupHalfStackOrDropSingleInteraction() {
}

void UItemSlotWidget::OnVisualInventoryItemRemoved_Implementation(UItemConfig* Config, int32 Amount, UObject* Origin) {
}

void UItemSlotWidget::OnVisualInventoryItemAdded_Implementation(UItemConfig* Config, int32 Amount, UObject* Origin) {
}

bool UItemSlotWidget::OnTransferItemInteraction() {
    return false;
}

void UItemSlotWidget::OnSetupWithInventory_Implementation(UInventoryComponent* InInventoryComponent, int32 TargetSlotIndex, bool bInIsPrediction) {
}

void UItemSlotWidget::OnInventorySlotChanged(const int32 TargetSlotIndex) {
}

void UItemSlotWidget::OnInteractionReleasedMouseKeyboard(const FPointerEvent& MouseEvent) {
}

void UItemSlotWidget::OnDropItem_Event_Implementation() {
}

bool UItemSlotWidget::IsEmpty() const {
    return false;
}

void UItemSlotWidget::DropItemStack() {
}

void UItemSlotWidget::CallLeftMouseShiftClick() {
}


