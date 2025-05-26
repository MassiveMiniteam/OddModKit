#include "DemandSimulationComponent.h"

UDemandSimulationComponent::UDemandSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StatsComponent = NULL;
    this->SimulationTimerComponent = NULL;
    this->DemandedItem = NULL;
}

void UDemandSimulationComponent::SatisfyDemand() {
}

void UDemandSimulationComponent::OnTimerFired(USimulationTimerComponent* InSimulationTimerComponent) {
}

UItemConfig* UDemandSimulationComponent::GetDemandedItem() const {
    return NULL;
}


