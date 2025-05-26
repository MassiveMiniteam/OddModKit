#include "TimedRadialSpawnerSimulationComponent.h"

UTimedRadialSpawnerSimulationComponent::UTimedRadialSpawnerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpawnAmount = 15;
    this->ProjectileLaunchType = EProjectileLaunchType::Throw;
    this->TargetTileRequirement = ERadialSpawnerTargetTileRequirement::Empty;
    this->MyPositionComponent = NULL;
    this->SpawnPattern = ESpawnPattern::Random;
    this->bUseProjectileSpawn = true;
    this->CurrentSpawnIndex = 0;
}

void UTimedRadialSpawnerSimulationComponent::SpawnAllAtOnce() {
}


