#include "GameplayEffectsPresentationComponent.h"

UGameplayEffectsPresentationComponent::UGameplayEffectsPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->IntervalBetweenSingleEffects = 0.75f;
    this->DelayAfterLastEffect = 5.00f;
    this->InitialDelay = 0.50f;
}

void UGameplayEffectsPresentationComponent::VisualizeNextEffect() {
}

void UGameplayEffectsPresentationComponent::OnGameplayEffectsListChanged(UStatsComponent* InStatsComponent) {
}


