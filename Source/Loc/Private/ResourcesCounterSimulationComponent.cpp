#include "ResourcesCounterSimulationComponent.h"

UResourcesCounterSimulationComponent::UResourcesCounterSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MyInventory = NULL;
}

void UResourcesCounterSimulationComponent::OnItemAdded(UItemConfig* Config, int32 Amount, UObject* Origin) {
}


