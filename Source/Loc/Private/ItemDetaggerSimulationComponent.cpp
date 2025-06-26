#include "ItemDetaggerSimulationComponent.h"

UItemDetaggerSimulationComponent::UItemDetaggerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InputInventory = NULL;
    this->OutputInventory_BaseItem = NULL;
    this->OutputInventory_TagItem = NULL;
}

UItemConfig* UItemDetaggerSimulationComponent::GetItemConfigForTag() const {
    return NULL;
}

FItemStack UItemDetaggerSimulationComponent::GetBaseItemStack() const {
    return FItemStack{};
}

bool UItemDetaggerSimulationComponent::CanUseDetagger() {
    return false;
}

bool UItemDetaggerSimulationComponent::CanAddItemsToTargetInventories() {
    return false;
}

FBaseItemTagItemPair UItemDetaggerSimulationComponent::CalculateOutput() {
    return FBaseItemTagItemPair{};
}


