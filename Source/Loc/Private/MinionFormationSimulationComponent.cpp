#include "MinionFormationSimulationComponent.h"

UMinionFormationSimulationComponent::UMinionFormationSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DistanceToLeader = 50;
}

void UMinionFormationSimulationComponent::UpdateMinionSlots() {
}

void UMinionFormationSimulationComponent::RemoveMinion(ASimulationActor* Minion) {
}

void UMinionFormationSimulationComponent::OnLeaderPositionChanged() {
}

FWeakActorArray UMinionFormationSimulationComponent::GetMinionsInFormationOfType(const FMinionConfigDataMapping& MinionConfigDataMapping) const {
    return FWeakActorArray{};
}

bool UMinionFormationSimulationComponent::GetMinionIsFollowing(const ASimulationActor* Minion) const {
    return false;
}

void UMinionFormationSimulationComponent::AddMinion(ASimulationActor* Minion) {
}


