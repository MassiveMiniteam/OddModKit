#include "DespawnOnDeathSimulationComponent.h"

UDespawnOnDeathSimulationComponent::UDespawnOnDeathSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StartTimerDirectlyOnSimulationBegin = false;
}

void UDespawnOnDeathSimulationComponent::StartDeathTimer() {
}

void UDespawnOnDeathSimulationComponent::OnDeathTriggered(UStatsComponent* StatsComp) {
}


