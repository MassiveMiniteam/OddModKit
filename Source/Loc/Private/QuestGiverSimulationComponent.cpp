#include "QuestGiverSimulationComponent.h"

UQuestGiverSimulationComponent::UQuestGiverSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->QuestManager = NULL;
    this->QuestInventory = NULL;
}

void UQuestGiverSimulationComponent::OnQuestListChanged(UQuestManagerSimulationComponent* QuestManagerSimulationComponent) {
}

void UQuestGiverSimulationComponent::OnQuestCompleted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer) {
}

void UQuestGiverSimulationComponent::OnQuestAborted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer) {
}

bool UQuestGiverSimulationComponent::HasActiveQuestOfType(UQuestConfig* QuestConfig) {
    return false;
}

TEnumAsByte<EQuestState> UQuestGiverSimulationComponent::GetQuestStateForQuestGiver(UQuestConfig* InQuestConfig) {
    return Unknown;
}

UInventoryComponent* UQuestGiverSimulationComponent::GetQuestInventory() const {
    return NULL;
}

AQuestInstance* UQuestGiverSimulationComponent::GetQuestInstanceOfType(UQuestConfig* QuestConfig) {
    return NULL;
}

TArray<AQuestInstance*> UQuestGiverSimulationComponent::GetCompletableQuests(ASimulationPlayer* SimulationPlayer) {
    return TArray<AQuestInstance*>();
}

FString UQuestGiverSimulationComponent::GetAvailableQuestsAsDebugString() {
    return TEXT("");
}

TArray<UQuestConfig*> UQuestGiverSimulationComponent::GetAvailableQuests(bool bIgnorePrerequisitesAndDisqualifiers) {
    return TArray<UQuestConfig*>();
}

TArray<UQuestConfig*> UQuestGiverSimulationComponent::GetAllQuestsForNPC() {
    return TArray<UQuestConfig*>();
}

TArray<AQuestInstance*> UQuestGiverSimulationComponent::GetActiveQuests() {
    return TArray<AQuestInstance*>();
}

void UQuestGiverSimulationComponent::ForceCallOnFinished() {
}

bool UQuestGiverSimulationComponent::CanCompleteAnyQuest(ASimulationPlayer* SimulationPlayer) {
    return false;
}


