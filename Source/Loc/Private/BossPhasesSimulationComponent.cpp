#include "BossPhasesSimulationComponent.h"
#include "Templates/SubclassOf.h"

UBossPhasesSimulationComponent::UBossPhasesSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActiveBossPhase = NULL;
    this->LastProgress = -1;
}

void UBossPhasesSimulationComponent::StartBossPhase(TSubclassOf<UBossPhase> BossPhaseClass) {
}

void UBossPhasesSimulationComponent::ResetGridPosition(FIntPoint& Pos) {
}

void UBossPhasesSimulationComponent::ResetActiveBossPhaseIgnoreIncubatorProgress(EBossResetReason Reason) {
}

void UBossPhasesSimulationComponent::ResetActiveBossPhase(EBossResetReason Reason) {
}

void UBossPhasesSimulationComponent::OnStatChanged(UStatsComponent* StatsComponentIn, FGameplayTag Tag, FFixed OldValue, FFixed NewValue) {
}

void UBossPhasesSimulationComponent::OnQuestAccepted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance) {
}

void UBossPhasesSimulationComponent::OnIncubatorProgressionChanged(UIncubatorSimulationComponent* Incubator, FFixed Progress) {
}

void UBossPhasesSimulationComponent::OnIncubatorCompleted(UIncubatorSimulationComponent* Incubator, FFixed Progress) {
}

void UBossPhasesSimulationComponent::InitReferences() {
}

UBossPhase* UBossPhasesSimulationComponent::GetActiveBossPhase() const {
    return NULL;
}

void UBossPhasesSimulationComponent::EndActiveBossPhase() {
}


