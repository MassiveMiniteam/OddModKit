#include "AnimationPresentationComponent.h"

UAnimationPresentationComponent::UAnimationPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseAggregatedTick = true;
    this->bForceStaticMeshTickOnce = false;
    this->SectionBlendValue = 0.10f;
}

void UAnimationPresentationComponent::StopAnimationWithTag(FGameplayTag Tag) {
}

void UAnimationPresentationComponent::StopAllAnimations() {
}

void UAnimationPresentationComponent::PlayAnimationWithTag(FGameplayTag Tag, float AnimationRate, float TimeToStartMontage, bool ChooseRandomFromContainer) {
}

void UAnimationPresentationComponent::PlayAnimationWithMetadataTag(FGameplayTag Tag, FGameplayTag MetaTag, float AnimationRate, float TimeToStartMontage) {
}

void UAnimationPresentationComponent::PlayAnimationDirectlyToLastFrame(FGameplayTag Tag, bool ChooseRandomFromContainer) {
}

void UAnimationPresentationComponent::OnStatChanged(UStatsComponent* StatsComponentIn, FGameplayTag Tag, FFixed OldValue, FFixed NewValue) {
}

bool UAnimationPresentationComponent::IsAnimationWithTagPlaying(FGameplayTag Tag) const {
    return false;
}

bool UAnimationPresentationComponent::ImplementsAnimationTag(FGameplayTag Tag) const {
    return false;
}

UAnimMontage* UAnimationPresentationComponent::GetAnimMontageByTag(FGameplayTag Tag) const {
    return NULL;
}

TArray<UAnimMetaData*> UAnimationPresentationComponent::GetAnimationMetaData(FGameplayTag Tag) const {
    return TArray<UAnimMetaData*>();
}


