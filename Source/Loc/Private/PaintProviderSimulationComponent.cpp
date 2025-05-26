#include "PaintProviderSimulationComponent.h"

UPaintProviderSimulationComponent::UPaintProviderSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PaintInventory = NULL;
}

FItemStack UPaintProviderSimulationComponent::PullColorItem(bool& bSuccess) {
    return FItemStack{};
}

bool UPaintProviderSimulationComponent::HasColorEquipped() {
    return false;
}

UColorItemConfig* UPaintProviderSimulationComponent::GetCurrentColorConfig() {
    return NULL;
}


