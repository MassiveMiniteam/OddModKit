#include "PathAddOn_ItemThroughputMeter_SimulationComponent.h"

UPathAddOn_ItemThroughputMeter_SimulationComponent::UPathAddOn_ItemThroughputMeter_SimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
}

void UPathAddOn_ItemThroughputMeter_SimulationComponent::OnFilterTimerFired(USimulationTimerComponent* SimulationTimerComponent) {
}


