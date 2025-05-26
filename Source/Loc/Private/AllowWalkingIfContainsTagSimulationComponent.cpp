#include "AllowWalkingIfContainsTagSimulationComponent.h"

UAllowWalkingIfContainsTagSimulationComponent::UAllowWalkingIfContainsTagSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CustomWalkabilityBitmaskOnTag = 255;
    this->StatsComponent = NULL;
}

void UAllowWalkingIfContainsTagSimulationComponent::OnGameplayStatChanged(UStatsComponent* InStatsComponent, FGameplayTag Tag, FFixed OldValue, FFixed NewValue) {
}


