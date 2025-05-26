#include "ButtonPromptWidget.h"

UButtonPromptWidget::UButtonPromptWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->InputActionData = NULL;
}


void UButtonPromptWidget::OnActiveDeviceChanged(UInputDeviceMapping* ActiveDevice) {
}



