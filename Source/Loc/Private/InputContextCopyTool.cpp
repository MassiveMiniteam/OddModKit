#include "InputContextCopyTool.h"

UInputContextCopyTool::UInputContextCopyTool() {
    this->CursorInputContext = NULL;
    this->bIsDragging = false;
    this->CopyToolMemoryComponent = NULL;
    this->InputAction_Confirm = NULL;
    this->InputAction_Cancel = NULL;
    this->CursorType = NULL;
    this->GridIndicatorClass = NULL;
    this->GamepadMovementInputContextClass = NULL;
    this->PasteToolInputContextClass = NULL;
}

void UInputContextCopyTool::OnNewCellHovered_Implementation(FIntPoint Cell, FIntPoint PreviousCell) {
}

void UInputContextCopyTool::OnLeftDragMode_Implementation() {
}

void UInputContextCopyTool::OnEnteredDragMode_Implementation() {
}

void UInputContextCopyTool::OnConfirm(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextCopyTool::OnCancel(UInputActionData* InputAction, ALocPlayerController* Player) {
}

FConstructionsCopyData UInputContextCopyTool::GetAllCopyDataFromDragArea() {
    return FConstructionsCopyData{};
}


