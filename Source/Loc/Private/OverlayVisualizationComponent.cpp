#include "OverlayVisualizationComponent.h"

UOverlayVisualizationComponent::UOverlayVisualizationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bVisualizationIsActive = false;
    this->UnlockableAction = NULL;
}

void UOverlayVisualizationComponent::ToggleVisualization() {
}

void UOverlayVisualizationComponent::StopVisualization() {
}

void UOverlayVisualizationComponent::StartVisualization() {
}



bool UOverlayVisualizationComponent::IsVisualizationCurrentlyActive() {
    return false;
}


