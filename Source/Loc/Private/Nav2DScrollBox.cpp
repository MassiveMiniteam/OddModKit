#include "Nav2DScrollBox.h"

UNav2DScrollBox::UNav2DScrollBox() {
    this->ScrollXAction = NULL;
    this->ScrollYAction = NULL;
    this->bInvertAxisInput = false;
    this->GamepadScrollSpeed = 50.00f;
    this->ActiveFocusPath = NULL;
}

void UNav2DScrollBox::OnScrollYInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UNav2DScrollBox::OnScrollXInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UNav2DScrollBox::OnFocusPathChanged(UNavFocusPath* PathIn) {
}

void UNav2DScrollBox::AddScroll(FVector2D ScrollAmount) {
}


