#include "PaintReceiverPresentationComponent.h"

UPaintReceiverPresentationComponent::UPaintReceiverPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PaintReceiverSimulationComponent = NULL;
}

void UPaintReceiverPresentationComponent::OnColorChanged(UPaintReceiverSimulationComponent* InPaintReceiverSimulationComponent, UColorItemConfig* ColorItem, FIntVector ImpactLocation, FFixed Delay) {
}


