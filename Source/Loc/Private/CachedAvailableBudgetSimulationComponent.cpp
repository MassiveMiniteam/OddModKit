#include "CachedAvailableBudgetSimulationComponent.h"

UCachedAvailableBudgetSimulationComponent::UCachedAvailableBudgetSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TimedTargetDetector = NULL;
}

void UCachedAvailableBudgetSimulationComponent::SetAvailableBudgetForInfluenceRadius(int32 AvailableBudget) {
}

int32 UCachedAvailableBudgetSimulationComponent::GetRadius() {
    return 0;
}


