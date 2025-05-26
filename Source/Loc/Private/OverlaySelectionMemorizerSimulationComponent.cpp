#include "OverlaySelectionMemorizerSimulationComponent.h"

UOverlaySelectionMemorizerSimulationComponent::UOverlaySelectionMemorizerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SelectedOverlayVisualizerClass = NULL;
    this->bIsVisible = false;
    this->bAllowOverlaySelection = false;
}


