#include "InputContextConstructionToolsGamepadMovement.h"

UInputContextConstructionToolsGamepadMovement::UInputContextConstructionToolsGamepadMovement() {
    this->CursorInputContext = NULL;
    this->InputAction_AxisX = NULL;
    this->InputAction_AxisY = NULL;
    this->InputAction_ToggleMovement = NULL;
    this->ZoomCurve = NULL;
    this->ControllerMoveSpeed = 1000.00f;
    this->InputContextSubsystem = NULL;
    this->SpringArmComponent = NULL;
}

void UInputContextConstructionToolsGamepadMovement::OnMoveYAxis(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextConstructionToolsGamepadMovement::OnMoveXAxis(UInputActionData* InputAction, ALocPlayerController* Player) {
}


void UInputContextConstructionToolsGamepadMovement::OnInputAction_ToggleMovement(UInputActionData* InputAction, ALocPlayerController* Player) {
}

bool UInputContextConstructionToolsGamepadMovement::GetAllowCharacterMovementForController() const {
    return false;
}


