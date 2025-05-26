#include "TokenGeneratorSimulationComponent.h"

UTokenGeneratorSimulationComponent::UTokenGeneratorSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ShopTokenItemConfig = NULL;
    this->TokenInventory = NULL;
}

void UTokenGeneratorSimulationComponent::SetTokenInventory(UInventoryComponent* InventoryComponent) {
}

UItemConfig* UTokenGeneratorSimulationComponent::GetTokenConfig() const {
    return NULL;
}

int64 UTokenGeneratorSimulationComponent::GetTargetScore() const {
    return 0;
}

int64 UTokenGeneratorSimulationComponent::GetCurrentScore() const {
    return 0;
}


