#include "StatsSyncPresentationComponent.h"

UStatsSyncPresentationComponent::UStatsSyncPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UStatsSyncPresentationComponent::OnGameplayStatChanged(UStatsComponent* StatsComponent, FGameplayTag Tag, FFixed OldValue, FFixed NewValue) {
}


