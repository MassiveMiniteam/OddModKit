#include "IdleAnimationPresentationComponent.h"

UIdleAnimationPresentationComponent::UIdleAnimationPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseAggregatedTick = true;
    this->CurrentIdleDuration = 0.00f;
    this->DurationIdlingBeforePlayingAnimationsMin = 5.00f;
    this->DurationIdlingBeforePlayingAnimationsMax = 5.00f;
    this->TimeBetweenAnimations = 20.00f;
    this->bWhenNotMoving = true;
    this->bWhenIdleAnimation = false;
    this->DurationIdlingBeforePlayingAnimations = 0.00f;
    this->bIsPlayingIdleBreak = false;
    this->bIsForceIdle = false;
}

void UIdleAnimationPresentationComponent::SetForceIdle(bool bForceIdleIn) {
}

void UIdleAnimationPresentationComponent::OnIdleBreakMontageStop(UAnimMontage* Montage, bool bInterrupted) {
}

void UIdleAnimationPresentationComponent::OnAnimationStopped(UAnimationPresentationComponent* AnimationPresentationComponent, FGameplayTag Tag) {
}

void UIdleAnimationPresentationComponent::OnAnimationPlayed(UAnimationPresentationComponent* AnimationPresentationComponent, FGameplayTag Tag) {
}

bool UIdleAnimationPresentationComponent::IsIdleing() const {
    return false;
}

bool UIdleAnimationPresentationComponent::IsIdleBreakAllowed() const {
    return false;
}


