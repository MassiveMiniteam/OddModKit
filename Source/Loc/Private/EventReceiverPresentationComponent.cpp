#include "EventReceiverPresentationComponent.h"

UEventReceiverPresentationComponent::UEventReceiverPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SimulationActor = NULL;
    this->EventSimulationComponent = NULL;
}

void UEventReceiverPresentationComponent::OnEventReceived(UEventSimulationComponent* InEventSimulationComponent, const FString& InEventID) {
}


