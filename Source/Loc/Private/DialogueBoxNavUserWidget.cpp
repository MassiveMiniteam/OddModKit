#include "DialogueBoxNavUserWidget.h"

UDialogueBoxNavUserWidget::UDialogueBoxNavUserWidget() {
    this->DialogueConfig = NULL;
    this->DialoguePlayerComponent = NULL;
}


void UDialogueBoxNavUserWidget::PrevSlide() {
}

void UDialogueBoxNavUserWidget::OnDialogueCancelled_Implementation(UDialoguePlayerComponent* DialoguePlayer, UDialogueConfig* Dialogue) {
}

void UDialogueBoxNavUserWidget::OnDialogSlideChanged_Implementation(UDialoguePlayerComponent* DialoguePlayer, FDialogueSlideConfig DialogueSlide) {
}

void UDialogueBoxNavUserWidget::OnDialogOver_Implementation(UDialoguePlayerComponent* DialoguePlayer, UDialogueConfig* Dialogue) {
}

void UDialogueBoxNavUserWidget::NextSlide() {
}


