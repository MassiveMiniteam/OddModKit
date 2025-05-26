#include "InputContextWorldCursor.h"

UInputContextWorldCursor::UInputContextWorldCursor() {
    this->MaxCursorDistance = 900.00f;
    this->CursorSpeed = 10.00f;
    this->MoveXAction = NULL;
    this->MoveYAction = NULL;
    this->MoveRightStickXAction = NULL;
    this->MoveRightStickYAction = NULL;
    this->LockTargetAction = NULL;
}

void UInputContextWorldCursor::OnMoveYInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextWorldCursor::OnMoveXInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextWorldCursor::OnMoveRightStickYInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextWorldCursor::OnMoveRightStickXInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextWorldCursor::OnLockTargetAction(UInputActionData* InputAction, ALocPlayerController* Player) {
}



bool UInputContextWorldCursor::IsLockedOn() const {
    return false;
}




