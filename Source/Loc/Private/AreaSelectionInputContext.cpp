#include "AreaSelectionInputContext.h"

UAreaSelectionInputContext::UAreaSelectionInputContext() {
    this->FinishSelectionAction = NULL;
    this->CancelInputAction = NULL;
    this->CursorInputContext = NULL;
    this->bAreaSelectionActive = false;
    this->CursorType = NULL;
    this->GridIndicatorClass = NULL;
    this->GamepadMovementInputContextClass = NULL;
}

void UAreaSelectionInputContext::TriggerAreaSelectionAction_Implementation(const TArray<FIntPoint>& Cells) {
}

void UAreaSelectionInputContext::SetBindingToInputActions(bool bEnabled) {
}

void UAreaSelectionInputContext::OnNewCellHovered_Implementation(FIntPoint Cell, FIntPoint PreviousCell) {
}



void UAreaSelectionInputContext::OnCancelInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UAreaSelectionInputContext::OnAreaSelectionAction(UInputActionData* InputAction, ALocPlayerController* Player) {
}


