#include "FoodSourceComponent.h"

UFoodSourceComponent::UFoodSourceComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MaxAmount = 20;
    this->AmountRemaining = 20;
}

void UFoodSourceComponent::OnReplenishTimerFired(USimulationTimerComponent* SimulationTimerComponent) {
}

int32 UFoodSourceComponent::GetRemainingAmount() const {
    return 0;
}


