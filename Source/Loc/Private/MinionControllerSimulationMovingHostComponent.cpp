#include "MinionControllerSimulationMovingHostComponent.h"

UMinionControllerSimulationMovingHostComponent::UMinionControllerSimulationMovingHostComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MinionFormationComponent = NULL;
}

int32 UMinionControllerSimulationMovingHostComponent::GetFollowingMinionCount(int32 MinionSlotIndex) const {
    return 0;
}


