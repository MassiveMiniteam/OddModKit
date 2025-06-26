#include "ItemTaggerSimulationComponent.h"

UItemTaggerSimulationComponent::UItemTaggerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InputSlot = 1;
    this->TagSlot = 0;
    this->InputInventory = NULL;
    this->OutputInventory = NULL;
}

FItemStack UItemTaggerSimulationComponent::GetTagItemStack() const {
    return FItemStack{};
}

FItemStack UItemTaggerSimulationComponent::GetBaseItemStack() const {
    return FItemStack{};
}

bool UItemTaggerSimulationComponent::CanCombineItems() {
    return false;
}


