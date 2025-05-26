#include "QuestManagerSimulationComponent.h"

UQuestManagerSimulationComponent::UQuestManagerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FirstQuest = NULL;
    this->SimulationManager = NULL;
    this->UnlockHandlingSimulationComponent = NULL;
}

void UQuestManagerSimulationComponent::RemovePinnedQuest(AQuestInstance* QuestInstance) {
}

void UQuestManagerSimulationComponent::PinQuest(AQuestInstance* QuestInstance) {
}

void UQuestManagerSimulationComponent::OnItemUnlocked(UUnlockableDataAsset* UnlockableDataAsset) {
}

void UQuestManagerSimulationComponent::OnAnyQuestStepBehaviourUpdated(UQuestStepBehaviour* QuestStep) {
}

bool UQuestManagerSimulationComponent::IsQuestDisqualified(UObject* WorldContextObject, UQuestConfig* QuestConfig) {
    return false;
}

bool UQuestManagerSimulationComponent::HasAvailableQuestsOfSameTier(UObject* WorldContextObject, UQuestConfig* InQuestConfig) {
    return false;
}

bool UQuestManagerSimulationComponent::HasAnyActiveBossQuest() {
    return false;
}

TArray<UQuestConfig*> UQuestManagerSimulationComponent::GetQuestsWithPrerequisite(UObject* WorldContextObject, UQuestConfig* QuestConfig) {
    return TArray<UQuestConfig*>();
}

TEnumAsByte<EQuestState> UQuestManagerSimulationComponent::GetQuestState(UQuestConfig* InQuestConfig) {
    return Unknown;
}

TArray<AQuestInstance*> UQuestManagerSimulationComponent::GetPinnedQuests() const {
    return TArray<AQuestInstance*>();
}

bool UQuestManagerSimulationComponent::ContainsActiveQuestOfType(UQuestConfig* QuestConfig) {
    return false;
}

void UQuestManagerSimulationComponent::CompleteQuest(AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer, bool bIgnoreConditions) {
}

bool UQuestManagerSimulationComponent::AreQuestPrerequisitsMet(UObject* WorldContextObject, UQuestConfig* QuestConfig) {
    return false;
}

AQuestInstance* UQuestManagerSimulationComponent::AcceptQuest(UQuestConfig* QuestData, UQuestGiverSimulationComponent* QuestGiver, bool bShouldPinQuest) {
    return NULL;
}

void UQuestManagerSimulationComponent::AcceptAutoStartQuestsIfPossible() {
}

void UQuestManagerSimulationComponent::AbortQuest(AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer) {
}


