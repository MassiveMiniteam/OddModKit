#include "DialogueQuestPromptWidget.h"

UDialogueQuestPromptWidget::UDialogueQuestPromptWidget() {
    this->QuestManager = NULL;
    this->QuestConfig = NULL;
}

void UDialogueQuestPromptWidget::OnQuestCompleted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer) {
}

void UDialogueQuestPromptWidget::OnQuestAccepted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance) {
}

void UDialogueQuestPromptWidget::Decline() {
}

void UDialogueQuestPromptWidget::Confirm(bool bShouldPinQuest) {
}

void UDialogueQuestPromptWidget::Complete() {
}

void UDialogueQuestPromptWidget::Cancel() {
}


