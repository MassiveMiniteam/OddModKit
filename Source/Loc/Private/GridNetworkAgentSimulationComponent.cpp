#include "GridNetworkAgentSimulationComponent.h"

UGridNetworkAgentSimulationComponent::UGridNetworkAgentSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UGridNetworkAgentSimulationComponent::SetAssignedNetwork(AGridNetwork* NewNetwork) {
}

void UGridNetworkAgentSimulationComponent::OnGridNetworkUpdated(AGridNetwork* Network) {
}

void UGridNetworkAgentSimulationComponent::OnGridNetworkDestroyed(AGridNetwork* Network) {
}

void UGridNetworkAgentSimulationComponent::OnArrivedAtNewTile(USubGridMovementSimulationComponent* Component) {
}

void UGridNetworkAgentSimulationComponent::IsAboutEnteringNewTile(USubGridMovementSimulationComponent* Component) {
}

bool UGridNetworkAgentSimulationComponent::HasValidAssignedNetwork() const {
    return false;
}

FIntPoint UGridNetworkAgentSimulationComponent::GetCurrentGridPosition() const {
    return FIntPoint{};
}

AGridNetwork* UGridNetworkAgentSimulationComponent::GetAssignedNetwork() const {
    return NULL;
}


