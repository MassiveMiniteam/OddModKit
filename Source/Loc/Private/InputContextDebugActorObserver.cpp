#include "InputContextDebugActorObserver.h"

UInputContextDebugActorObserver::UInputContextDebugActorObserver() {
    this->MoveXAction = NULL;
    this->MoveYAction = NULL;
    this->EndContextAction = NULL;
    this->ToggleDebugUIVisibilityAction = NULL;
    this->FocusDebugUIAction = NULL;
    this->SelectActorsAction = NULL;
    this->RemoveActorsAction = NULL;
    this->DebugCursorType = NULL;
    this->DebugCursorInstance = NULL;
    this->MaxCursorDistance = 900.00f;
    this->CursorSpeed = 10.00f;
}

void UInputContextDebugActorObserver::RemoveActor_Implementation(AActor* Actor) {
}

void UInputContextDebugActorObserver::OnToggleDebugUIVisibilityAction_Implementation(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextDebugActorObserver::OnSelectActorsAction(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextDebugActorObserver::OnRemoveActorsAction(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextDebugActorObserver::OnMoveYInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextDebugActorObserver::OnMoveXInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextDebugActorObserver::OnFocusDebugUIAction_Implementation(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextDebugActorObserver::OnEndContextAction(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextDebugActorObserver::AddActor_Implementation(AActor* Actor) {
}


