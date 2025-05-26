#include "GridNetworkSimulationComponent.h"

UGridNetworkSimulationComponent::UGridNetworkSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UGridNetworkSimulationComponent::UpdateConnection(const TArray<FIntPoint>& NewConnections) {
}

bool UGridNetworkSimulationComponent::IsConnectedNeighbour(UGridNetworkSimulationComponent* CompareComponent) {
    return false;
}

FIntPoint UGridNetworkSimulationComponent::GetGridPosition() const {
    return FIntPoint{};
}


