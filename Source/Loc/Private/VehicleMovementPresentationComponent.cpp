#include "VehicleMovementPresentationComponent.h"

UVehicleMovementPresentationComponent::UVehicleMovementPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurrentDriver = NULL;
    this->VehicleSimulationComponent = NULL;
}

void UVehicleMovementPresentationComponent::ResetLastAndPrevPositions() {
}

void UVehicleMovementPresentationComponent::OnSimActorRemoved(UVehicleSimulationComponent* Component, ASimulationActor* SimulationActor, int32 Index) {
}

void UVehicleMovementPresentationComponent::OnSimActorAdded(UVehicleSimulationComponent* Component, ASimulationActor* SimulationActor, int32 Index) {
}


