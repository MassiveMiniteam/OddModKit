#include "TabButton.h"

UTabButton::UTabButton() : UUserWidget(FObjectInitializer::Get()) {
    this->TabIndex = 0;
    this->TabHeadline = NULL;
}

void UTabButton::UpdateButtonText(FText NewButtonText) {
}

void UTabButton::OnTabIndexChanged_Implementation(int32 NewIndex) {
}


