#include "PaintReceiverSimulationComponent.h"

UPaintReceiverSimulationComponent::UPaintReceiverSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurrentColorItem = NULL;
    this->DefaultColorItem = NULL;
}

UColorItemConfig* UPaintReceiverSimulationComponent::ReturnCurrentOrDefaultColor() {
    return NULL;
}

void UPaintReceiverSimulationComponent::Reset(FIntVector ImpactLocation, FFixed Delay) {
}

void UPaintReceiverSimulationComponent::Paint(UColorItemConfig* ColorItem, FIntVector ImpactLocation, FFixed Delay) {
}


