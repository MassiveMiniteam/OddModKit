#include "BalloonCarryPresentationComponent.h"

UBalloonCarryPresentationComponent::UBalloonCarryPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BalloonCarrySimulationComponent = NULL;
}

void UBalloonCarryPresentationComponent::OnBalloonRemoved_Event_Implementation() {
}

void UBalloonCarryPresentationComponent::OnBalloonReleased(UBalloonCarrySimulationComponent* Component) {
}

void UBalloonCarryPresentationComponent::OnBalloonAttached_Event_Implementation() {
}

void UBalloonCarryPresentationComponent::OnBalloonAttached(UBalloonCarrySimulationComponent* Component) {
}


