#include "DemandPresentationComponent.h"

UDemandPresentationComponent::UDemandPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DemandSimulationComponent = NULL;
}

void UDemandPresentationComponent::OnGameplayEffectStatusPolled_Implementation(UDemandSimulationComponent* Component, bool bState) {
}


