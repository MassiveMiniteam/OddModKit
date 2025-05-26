#include "QuestToastsSubsystem.h"

UQuestToastsSubsystem::UQuestToastsSubsystem() {
    this->QuestManager = NULL;
}

void UQuestToastsSubsystem::UnregisterQuestManager(UQuestManagerSimulationComponent* InQuestManager) {
}

void UQuestToastsSubsystem::RegisterQuestManager(UQuestManagerSimulationComponent* InQuestManager) {
}

void UQuestToastsSubsystem::OnQuestCompleted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer) {
}

void UQuestToastsSubsystem::OnQuestAccepted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance) {
}

UQuestConfig* UQuestToastsSubsystem::DequeueCompletedQuest(bool& bSuccess) {
    return NULL;
}

UQuestConfig* UQuestToastsSubsystem::DequeueAcceptedQuest(bool& bSuccess) {
    return NULL;
}


