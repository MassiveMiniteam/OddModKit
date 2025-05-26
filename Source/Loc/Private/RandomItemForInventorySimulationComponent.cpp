#include "RandomItemForInventorySimulationComponent.h"

URandomItemForInventorySimulationComponent::URandomItemForInventorySimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LootTable = NULL;
    this->LootAmount = 1;
}


