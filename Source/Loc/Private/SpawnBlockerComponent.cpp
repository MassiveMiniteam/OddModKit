#include "SpawnBlockerComponent.h"

USpawnBlockerComponent::USpawnBlockerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BlockRadius = 1000;
    this->PositionSimulationComponent = NULL;
    this->StatsComponent = NULL;
}

void USpawnBlockerComponent::OnStatBoolRemoved(UStatsComponent* InStatsComponent, FGameplayTag Tag) {
}

void USpawnBlockerComponent::OnStatBoolAdded(UStatsComponent* InStatsComponent, FGameplayTag Tag) {
}

bool USpawnBlockerComponent::IsWorldPositionInRange(const FIntVector& WorldPosition) const {
    return false;
}

bool USpawnBlockerComponent::IsBlocked(const FIntVector& WorldPosition, TSoftClassPtr<ASimulationActor> ActorClass) const {
    return false;
}

bool USpawnBlockerComponent::DoesCareAboutClass(TSoftClassPtr<ASimulationActor> ActorClass) const {
    return false;
}


