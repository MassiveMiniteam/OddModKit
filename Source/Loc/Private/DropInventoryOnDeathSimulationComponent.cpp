#include "DropInventoryOnDeathSimulationComponent.h"

UDropInventoryOnDeathSimulationComponent::UDropInventoryOnDeathSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpawnedInventoryActorClass = NULL;
}

void UDropInventoryOnDeathSimulationComponent::OnOwnerDied(UStatsComponent* StatsComponent) {
}

void UDropInventoryOnDeathSimulationComponent::DropInventoryToPosition(FIntVector Location, int32 Rotation) {
}


