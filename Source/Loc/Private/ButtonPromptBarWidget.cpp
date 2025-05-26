#include "ButtonPromptBarWidget.h"

UButtonPromptBarWidget::UButtonPromptBarWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->bIsMainPromptBar = false;
    this->BarBox = NULL;
}

void UButtonPromptBarWidget::PushButtonPromptSet(UButtonPromptBarItemSet* ButtonPrompts) {
}

void UButtonPromptBarWidget::PopButtonPromptSet(UButtonPromptBarItemSet* ButtonPrompts) {
}


