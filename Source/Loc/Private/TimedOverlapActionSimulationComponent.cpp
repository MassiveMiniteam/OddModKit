#include "TimedOverlapActionSimulationComponent.h"

UTimedOverlapActionSimulationComponent::UTimedOverlapActionSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bStayActive = false;
    this->bActivated = false;
    this->MyPositionComponent = NULL;
}

void UTimedOverlapActionSimulationComponent::OnGridPositionOverlap(UPositionSimulationComponent* ThisComponent, UPositionSimulationComponent* OtherComponent) {
}


