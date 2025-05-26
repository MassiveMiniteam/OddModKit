#include "UnitGroupMemberSimulationComponent.h"

UUnitGroupMemberSimulationComponent::UUnitGroupMemberSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Group = NULL;
    this->GettingAttackedComponent = NULL;
}

void UUnitGroupMemberSimulationComponent::SetGroup(UUnitGroup* NewGroup) {
}

void UUnitGroupMemberSimulationComponent::OnStatBoolAdded(UStatsComponent* StatsComp, FGameplayTag Tag) {
}

void UUnitGroupMemberSimulationComponent::OnGettingAttacked(UGettingAttackedSimulationComponent* Component, ASimulationActor* Instigator, UGameplayAbility* Ability, bool bSuccess) {
}

TArray<UUnitGroupMemberSimulationComponent*> UUnitGroupMemberSimulationComponent::GetOtherGroupMembers() const {
    return TArray<UUnitGroupMemberSimulationComponent*>();
}

UUnitGroup* UUnitGroupMemberSimulationComponent::GetGroup() const {
    return NULL;
}

UUnitGroup* UUnitGroupMemberSimulationComponent::CreateNewGroupAndAssignSelf() {
    return NULL;
}


