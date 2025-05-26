#include "VehiclePassengersPresentationComponent.h"

UVehiclePassengersPresentationComponent::UVehiclePassengersPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->VehicleSimulationComponent = NULL;
}

void UVehiclePassengersPresentationComponent::OnSimActorRemoved_Implementation(UVehicleSimulationComponent* Component, ASimulationActor* SimulationActor, int32 Index) {
}

void UVehiclePassengersPresentationComponent::OnSimActorAdded_Implementation(UVehicleSimulationComponent* Component, ASimulationActor* SimulationActor, int32 Index) {
}


