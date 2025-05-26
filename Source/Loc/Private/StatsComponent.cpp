#include "StatsComponent.h"
#include "Templates/SubclassOf.h"

UStatsComponent::UStatsComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->bKeepTicking = false;
    this->StatsContainer = NULL;
}

void UStatsComponent::SetStatBool(FGameplayTag Tag, bool Value) {
}

void UStatsComponent::SetStat(FGameplayTag Tag, FFixed Value) {
}

void UStatsComponent::RemoveStatModifiersScaled(FGameplayTag Tag, const TArray<FGameplayStatModifier>& Modifiers, FFixed Scale) {
}

void UStatsComponent::RemoveStatModifiersByTag(FGameplayTag StatTag, FGameplayTag ModifierTag) {
}

void UStatsComponent::RemoveStatModifiers(FGameplayTag Tag, const TArray<FGameplayStatModifier>& Modifiers) {
}

void UStatsComponent::RemoveStatModifier(FGameplayTag Tag, const FGameplayStatModifier& Modifier) {
}

void UStatsComponent::RemoveSingleGameplayEffectByType(TSubclassOf<UGameplayEffect> GameplayEffectType) {
}

void UStatsComponent::RemoveGameplayEffect(UGameplayEffect* GameplayEffect) {
}

void UStatsComponent::RemoveAllGameplayEffects() {
}

bool UStatsComponent::IsAnyStatBoolTrue(FGameplayTagContainer Tags) {
    return false;
}

int32 UStatsComponent::IncrementStatValue(FGameplayTag Tag) {
    return 0;
}

bool UStatsComponent::HasTag(FGameplayTag Tag) const {
    return false;
}

bool UStatsComponent::HasAnyTag(FGameplayTagContainer Tags) const {
    return false;
}

bool UStatsComponent::HasAllTags(FGameplayTagContainer Tags) const {
    return false;
}

FFixed UStatsComponent::GetStatValue(FGameplayTag Tag) const {
    return FFixed{};
}

bool UStatsComponent::GetStatBoolSimple(FGameplayTag Tag) const {
    return false;
}

void UStatsComponent::GetStatBool(FGameplayTag Tag, EGameplayStatBoolState& OutStatBoolState) {
}

bool UStatsComponent::GetHasTickingGameplayEffect() const {
    return false;
}

UGameplayEffect* UStatsComponent::FindActiveGameplayEffect(TSubclassOf<UGameplayEffect> GameplayEffectType) const {
    return NULL;
}

bool UStatsComponent::ContainsGameplayEffect(TSubclassOf<UGameplayEffect> GameplayEffectType) {
    return false;
}

bool UStatsComponent::AreAllStatBoolsTrue(FGameplayTagContainer Tags) {
    return false;
}

void UStatsComponent::ApplyInitialEffects() {
}

UGameplayEffect* UStatsComponent::ApplyGameplayEffectClass(TSubclassOf<UGameplayEffect> GameplayEffectClass, bool bIgnoreApplicationChecks, ASimulationActor* InstigatorIn) {
    return NULL;
}

bool UStatsComponent::ApplyGameplayEffect(UGameplayEffect* GameplayEffect, bool bIgnoreApplicationChecks) {
    return false;
}

void UStatsComponent::AddToStat(FGameplayTag Tag, FFixed Value, FFixed& OutStatValue) {
}

void UStatsComponent::AddStatModifiersScaled(FGameplayTag Tag, const TArray<FGameplayStatModifier>& Modifiers, FFixed Scale) {
}

void UStatsComponent::AddStatModifiers(FGameplayTag Tag, const TArray<FGameplayStatModifier>& Modifiers) {
}

void UStatsComponent::AddStatModifier(FGameplayTag Tag, const FGameplayStatModifier& Modifier) {
}


