#include "RadialMenu.h"

URadialMenu::URadialMenu() {
    this->RadialMenuSelectionHorizontalInput = NULL;
    this->RadialMenuSelectionVerticalInput = NULL;
    this->ConfirmInputAction = NULL;
    this->CancelInputAction = NULL;
    this->ToggleRadialMenuInputAction = NULL;
    this->MaxHoldDurationToStayOnScreen = 0.30f;
    this->RadialBox = NULL;
    this->HoveredButton = NULL;
    this->InputContextSubsystem = NULL;
    this->CoyoteTimeOnAxisRelease = 0.10f;
    this->CoyoteButton = NULL;
}

void URadialMenu::OnToggleRadialMenuInputAction_Implementation() {
}

void URadialMenu::OnRadialMenuSelectionAxisInput_Implementation(FVector2D AxisInput, bool bDirectionIndicatorIsVisible) {
}

void URadialMenu::OnConfirmInputAction_Implementation() {
}

void URadialMenu::OnCancelInputAction_Implementation() {
}

bool URadialMenu::HasInputForMouse(FVector2D TargetPosition) {
    return false;
}

bool URadialMenu::HasInputForController(FVector2D Direction) {
    return false;
}

FVector2D URadialMenu::GetMouseCursorPosition() const {
    return FVector2D{};
}


