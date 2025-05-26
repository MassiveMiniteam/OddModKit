#include "HostilityLevelSimulationComponent.h"

UHostilityLevelSimulationComponent::UHostilityLevelSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EvolutionBudgetTable = NULL;
    this->KillCounterHostilityPoints = 0;
    this->CachedEnemyHostilityIncreaseValuesTable = NULL;
}

void UHostilityLevelSimulationComponent::SetKillPoints(int32 Points) {
}

void UHostilityLevelSimulationComponent::RegisterActorForHostilityIncreaseOnDeath(ASimulationActor* Actor) {
}

void UHostilityLevelSimulationComponent::OnActorDied(UStatsComponent* StatsComponent) {
}

int32 UHostilityLevelSimulationComponent::GetMaxLevel() const {
    return 0;
}

int32 UHostilityLevelSimulationComponent::GetLevelForPoints(int32 KillPoints) const {
    return 0;
}

int32 UHostilityLevelSimulationComponent::GetKillPoints() const {
    return 0;
}

int32 UHostilityLevelSimulationComponent::GetHostilityIncreaseValue(TSoftClassPtr<ASimulationActor> EnemyClass) const {
    return 0;
}

FEvolutionBudget UHostilityLevelSimulationComponent::GetEvolutionBudgetForLevel(int32 Level, bool& bSuccess) const {
    return FEvolutionBudget{};
}

int32 UHostilityLevelSimulationComponent::GetCurrentLevel() const {
    return 0;
}

FEvolutionBudget UHostilityLevelSimulationComponent::GetCurrentEvolutionData() const {
    return FEvolutionBudget{};
}

void UHostilityLevelSimulationComponent::AddKillPoints(int32 Amount) {
}


