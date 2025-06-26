#include "RandomRadialSpawnerSimulationComponent.h"

URandomRadialSpawnerSimulationComponent::URandomRadialSpawnerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpawnAmount = 15;
    this->ProjectileLaunchType = EProjectileLaunchType::Throw;
    this->bFilterTargetTileForGridObject = true;
    this->bFilterTargetTileForWalkability = false;
    this->bFilterTargetTileForHeight = false;
    this->MyPositionComponent = NULL;
}

void URandomRadialSpawnerSimulationComponent::SpawnObjectsWithProjectilePayload(UObject* ProjectilePayload) {
}

void URandomRadialSpawnerSimulationComponent::SpawnObjects() {
}

FIntVector URandomRadialSpawnerSimulationComponent::GetSpawnRange() const {
    return FIntVector{};
}


