#include "DialoguePlayerComponent.h"

UDialoguePlayerComponent::UDialoguePlayerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DialogueConfig = NULL;
    this->DialogueIndex = 0;
    this->DialogUIClass = NULL;
}

void UDialoguePlayerComponent::Show(UDialogueConfig* InDialogueConfig) {
}

void UDialoguePlayerComponent::OnDialogueWidgetFinished(UDialogueBoxNavUserWidget* DialogueBox) {
}

int32 UDialoguePlayerComponent::GetDialogueIndex() const {
    return 0;
}

void UDialoguePlayerComponent::CancelDialogue() {
}


