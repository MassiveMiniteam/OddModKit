#include "BTStateMachineComponent.h"
#include "Templates/SubclassOf.h"

UBTStateMachineComponent::UBTStateMachineComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->StateGroupDefinitions = NULL;
    this->CurrentStateGroup = NULL;
    this->CurrentState = NULL;
    this->NextDesiredState = NULL;
    this->bForceBothNextDesiredStateAndStateGroupUpdatesSimultaneously = false;
    this->GettingAttackedComponent = NULL;
}

void UBTStateMachineComponent::RequestTransitionToStateGroupWhenCurrentStateFinishes(FGameplayTag StateGroupTag) {
}

void UBTStateMachineComponent::RequestTransitionToStateGroup(FGameplayTag StateGroupTag) {
}

void UBTStateMachineComponent::RequestTransitionToState(TSubclassOf<UBaseState> NewState) {
}

void UBTStateMachineComponent::RequestTransitionMostDesiredToState() {
}

void UBTStateMachineComponent::OnUtilityTimerFired(USimulationTimerComponent* SimulationTimerComponent) {
}

void UBTStateMachineComponent::OnStatBoolRemoved(UStatsComponent* StatsComponent, FGameplayTag Tag) {
}

void UBTStateMachineComponent::OnGettingAttacked(UGettingAttackedSimulationComponent* Component, ASimulationActor* Instigator, UGameplayAbility* Ability, bool bSuccess) {
}

void UBTStateMachineComponent::OnBehaviorTreeFinished(bool bIsLooping) {
}

bool UBTStateMachineComponent::IsValidStateGroupTag(FGameplayTag Tag) const {
    return false;
}

UStateGroupMappingAsset* UBTStateMachineComponent::GetStateGroupDefinitions() const {
    return NULL;
}

FGameplayTag UBTStateMachineComponent::GetNextDesiredStateGroupTag() const {
    return FGameplayTag{};
}

TSubclassOf<UBaseState> UBTStateMachineComponent::GetNextDesiredState() const {
    return NULL;
}

FGameplayTag UBTStateMachineComponent::GetCurrentStateGroupTag() const {
    return FGameplayTag{};
}

UStateGroup* UBTStateMachineComponent::GetCurrentStateGroup() const {
    return NULL;
}

UBaseState* UBTStateMachineComponent::GetCurrentState() const {
    return NULL;
}

TArray<TSubclassOf<UStateConditionStrategy>> UBTStateMachineComponent::GetCurrentCancelConditions() const {
    return TArray<TSubclassOf<UStateConditionStrategy>>();
}


