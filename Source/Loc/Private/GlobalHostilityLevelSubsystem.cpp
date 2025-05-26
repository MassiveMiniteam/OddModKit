#include "GlobalHostilityLevelSubsystem.h"

UGlobalHostilityLevelSubsystem::UGlobalHostilityLevelSubsystem() {
    this->KillCounterHostilityPoints = 100;
    this->CachedEnemyHostilityIncreaseValuesTable = NULL;
}

void UGlobalHostilityLevelSubsystem::RegisterActorForHostilityIncreaseOnDeath(ASimulationActor* Actor) {
}

void UGlobalHostilityLevelSubsystem::OnActorDied(UStatsComponent* StatsComponent) {
}

FFixed UGlobalHostilityLevelSubsystem::GetRelativeLevel() const {
    return FFixed{};
}

int32 UGlobalHostilityLevelSubsystem::GetNeededKillPointsForLevel(int32 Level) {
    return 0;
}

int32 UGlobalHostilityLevelSubsystem::GetMaxLevel() {
    return 0;
}

int32 UGlobalHostilityLevelSubsystem::GetKillPoints() const {
    return 0;
}

int32 UGlobalHostilityLevelSubsystem::GetCurrentHostilityLevel() const {
    return 0;
}

void UGlobalHostilityLevelSubsystem::AddKillPoints(int32 Amount) {
}


