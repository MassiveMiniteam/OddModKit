#include "NavSlider.h"

UNavSlider::UNavSlider() {
    this->MouseUsesStep = true;
    this->bInteractable = true;
    this->bNavigable = true;
    this->bUnhoverRemovesFocus = false;
}

void UNavSlider::SetNavSliderValueWithoutDelegate(float NewValue) {
}

void UNavSlider::SetNavSliderValue(float NewValue) {
}

void UNavSlider::SetMouseUsesSteps(bool bNewMouseUsesSteps) {
}

void UNavSlider::AcceptValue() {
}


