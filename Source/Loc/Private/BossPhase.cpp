#include "BossPhase.h"

UBossPhase::UBossPhase() {
    this->ActiveSubPhaseIndex = -1;
    this->ActiveRecipe = NULL;
}

void UBossPhase::UpdateHostilityLevelForCurrentSubphase() {
}

void UBossPhase::StartPhase() {
}

void UBossPhase::ResetPhase(EBossResetReason Reason) {
}

void UBossPhase::PhaseProgressChanged(int32 LastProgress, int32 CurrentProgress) {
}

void UBossPhase::OnStopSubPhase_Implementation(const FBossSubPhase& Subphase) {
}

void UBossPhase::OnStartSubPhase_Implementation(const FBossSubPhase& Subphase) {
}



void UBossPhase::OnQuestCompleted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer) {
}




void UBossPhase::Init() {
}

int32 UBossPhase::GetActiveSubPhaseIndex() const {
    return 0;
}

void UBossPhase::EndPhase() {
}


