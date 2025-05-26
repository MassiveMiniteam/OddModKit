#include "NPCDialogueHandlerPresentationComponent.h"

UNPCDialogueHandlerPresentationComponent::UNPCDialogueHandlerPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CachedDialogueQuestPromptWidget = NULL;
    this->CachedQuestSelectorWidget = NULL;
    this->bAllowOpenUIForActiveQuests = true;
    this->QuestSelectorWidgetType = NULL;
    this->QuestDialogWidgetType = NULL;
    this->CachedQuestConfig = NULL;
    this->CompletedQuestConfig = NULL;
}

void UNPCDialogueHandlerPresentationComponent::StartDialogue() {
}

void UNPCDialogueHandlerPresentationComponent::OnSecondaryDialogueOver(UDialoguePlayerComponent* InDialoguePlayerComponent, UDialogueConfig* Dialogue) {
}

void UNPCDialogueHandlerPresentationComponent::OnQuestSelectionCancelled(UNPCQuestSelectorWidget* Widget) {
}

void UNPCDialogueHandlerPresentationComponent::OnQuestPromptWidgetClosed(UDialogueQuestPromptWidget* Widget, UQuestConfig* QuestConfig) {
}

void UNPCDialogueHandlerPresentationComponent::OnQuestInteractionCancelled(UDialogueQuestPromptWidget* Widget, UQuestConfig* QuestConfig) {
}

void UNPCDialogueHandlerPresentationComponent::OnQuestConfigSelected(UNPCQuestSelectorWidget* Widget, UQuestConfig* QuestConfig) {
}

void UNPCDialogueHandlerPresentationComponent::OnQuestCompletedDialogueLineOver(UDialoguePlayerComponent* InDialoguePlayerComponent, UDialogueConfig* Dialogue) {
}

void UNPCDialogueHandlerPresentationComponent::OnQuestCompleted(UDialogueQuestPromptWidget* Widget, UQuestConfig* QuestConfig) {
}

void UNPCDialogueHandlerPresentationComponent::OnOfferedQuestAccepted(UDialogueQuestPromptWidget* Widget, UQuestConfig* QuestConfig) {
}

void UNPCDialogueHandlerPresentationComponent::OnInitialDialogueOver(UDialoguePlayerComponent* InDialoguePlayerComponent, UDialogueConfig* Dialogue) {
}

void UNPCDialogueHandlerPresentationComponent::OnDialogueCancelled(UDialoguePlayerComponent* InDialoguePlayerComponent, UDialogueConfig* Dialogue) {
}


