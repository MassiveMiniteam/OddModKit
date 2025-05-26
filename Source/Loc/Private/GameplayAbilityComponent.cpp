#include "GameplayAbilityComponent.h"
#include "Templates/SubclassOf.h"

UGameplayAbilityComponent::UGameplayAbilityComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->DefaultAbility = NULL;
    this->RestoreAbility = NULL;
    this->ActiveAbility = NULL;
    this->NextAbilityClass = NULL;
}

void UGameplayAbilityComponent::StartNextAbility() {
}

void UGameplayAbilityComponent::StartAbility_Internal(TSubclassOf<UGameplayAbility> AbilityClass) {
}

void UGameplayAbilityComponent::SetNextAbilityByPriorities() {
}

void UGameplayAbilityComponent::SetNextAbility(TSubclassOf<UGameplayAbility> AbilityClass) {
}

void UGameplayAbilityComponent::OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem) {
}

void UGameplayAbilityComponent::OnActiveAbilityFinished() {
}

TSubclassOf<UGameplayAbility> UGameplayAbilityComponent::GetNextAbility() const {
    return NULL;
}

ASimulationActor* UGameplayAbilityComponent::GetCurrentTargetActor() const {
    return NULL;
}

EAbilityStatus UGameplayAbilityComponent::GetCurrentAbilityStatus() const {
    return EAbilityStatus::Inactive;
}

void UGameplayAbilityComponent::ClearNextAbility() {
}

void UGameplayAbilityComponent::CancelActiveAbility() {
}

bool UGameplayAbilityComponent::AreAllAbilityConditionsFulfilled(TSubclassOf<UGameplayAbility> AbilityClass) const {
    return false;
}


