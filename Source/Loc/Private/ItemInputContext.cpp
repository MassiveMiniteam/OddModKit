#include "ItemInputContext.h"

UItemInputContext::UItemInputContext() {
    this->Inventory = NULL;
    this->SlotIndex = 0;
    this->RotateLeftAction = NULL;
    this->RotateRightAction = NULL;
    this->UseItemAction = NULL;
    this->CancelAction = NULL;
    this->UseSpecialAction = NULL;
}

void UItemInputContext::OnUseSpecialInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UItemInputContext::OnUseSpecial_Implementation() {
}

void UItemInputContext::OnUseItemInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UItemInputContext::OnUseItem_Implementation() {
}

void UItemInputContext::OnRotateRightInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UItemInputContext::OnRotateRight_Implementation() {
}

void UItemInputContext::OnRotateLeftInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UItemInputContext::OnRotateLeft_Implementation() {
}

void UItemInputContext::OnCancelInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UItemInputContext::OnCancel_Implementation() {
}


