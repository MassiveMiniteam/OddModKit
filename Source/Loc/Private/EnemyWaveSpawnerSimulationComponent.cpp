#include "EnemyWaveSpawnerSimulationComponent.h"
#include "Templates/SubclassOf.h"

UEnemyWaveSpawnerSimulationComponent::UEnemyWaveSpawnerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DefaultStrategy = NULL;
    this->bIsAffectedBySpawnBlocker = false;
    this->ActiveStrategy = NULL;
    this->CachedPositionComponent = NULL;
}

void UEnemyWaveSpawnerSimulationComponent::StopWave() {
}

void UEnemyWaveSpawnerSimulationComponent::StartWaveWithDefaultStrategy() {
}

void UEnemyWaveSpawnerSimulationComponent::StartWaveWithCustomStrategy(TSubclassOf<UEnemySpawnStrategy> Strategy) {
}

void UEnemyWaveSpawnerSimulationComponent::OnUnitDied(UStatsComponent* StatsComponent) {
}

void UEnemyWaveSpawnerSimulationComponent::OnTimerStoppedCallback(USimulationTimerComponent* SimulationTimerComponent) {
}

void UEnemyWaveSpawnerSimulationComponent::KillAllMonster() {
}

bool UEnemyWaveSpawnerSimulationComponent::IsWaveCompletelySpawned() const {
    return false;
}

bool UEnemyWaveSpawnerSimulationComponent::IsCurrentlyAffectedBySpawnBlocker() {
    return false;
}

int32 UEnemyWaveSpawnerSimulationComponent::GetRemainingBudget() const {
    return 0;
}

FFixed UEnemyWaveSpawnerSimulationComponent::GetRelativeRemainingBudget() const {
    return FFixed{};
}

int32 UEnemyWaveSpawnerSimulationComponent::GetCurrentTotalBudget() const {
    return 0;
}

TArray<ASimulationActor*> UEnemyWaveSpawnerSimulationComponent::GetCurrentMonsters() const {
    return TArray<ASimulationActor*>();
}

void UEnemyWaveSpawnerSimulationComponent::AddExternalMonster(ASimulationActor* InExternalMonster) {
}


