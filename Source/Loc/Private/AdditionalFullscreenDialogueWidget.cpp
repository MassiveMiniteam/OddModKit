#include "AdditionalFullscreenDialogueWidget.h"

UAdditionalFullscreenDialogueWidget::UAdditionalFullscreenDialogueWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->DialoguePlayer = NULL;
}

void UAdditionalFullscreenDialogueWidget::SetDialoguePlayer(UDialoguePlayerComponent* DialoguePlayerComponent) {
}


void UAdditionalFullscreenDialogueWidget::OnDialogueSlideChanged(UDialoguePlayerComponent* InDialoguePlayer, int32 Index) {
}


