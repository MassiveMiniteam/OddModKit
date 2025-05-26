#include "MonsterSpawnerSimulationComponent.h"

UMonsterSpawnerSimulationComponent::UMonsterSpawnerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bStartTickEnabled = true;
    this->bForceTicking = true;
    this->bDisableSpawnWhenBuildingNearby = false;
    this->bCountSpawnedEnemiesTowardsHostilitySystem = false;
    this->InitialMonsterCount = 0;
    this->MaxMonsterCount = 0;
    this->PlayerSpawnBlockRadius = 2000;
    this->SpawnRandomRadius = 0;
    this->SpawnWithRandomRotation = true;
    this->bSpawnedMonstersFormUnitGroup = false;
    this->MonstersLastFrame = 0;
}

void UMonsterSpawnerSimulationComponent::OnTimerFired(USimulationTimerComponent* TimerComponent) {
}

void UMonsterSpawnerSimulationComponent::OnMonsterStatDead(UStatsComponent* StatsComponent) {
}

void UMonsterSpawnerSimulationComponent::OnMonsterShutdown(ASimulationActor* InSimulationActor, EDestructionReason Reason) {
}

void UMonsterSpawnerSimulationComponent::OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem) {
}

TArray<ASimulationActor*> UMonsterSpawnerSimulationComponent::GetReferencesMonsters() const {
    return TArray<ASimulationActor*>();
}


