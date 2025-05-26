#include "VehicleSimulationComponent.h"

UVehicleSimulationComponent::UVehicleSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Seats.AddDefaulted(3);
}

bool UVehicleSimulationComponent::TryAddSimulationActor(ASimulationActor* InSimulationActor) {
    return false;
}

bool UVehicleSimulationComponent::RemoveSimulationActor(ASimulationActor* InSimulationActor) {
    return false;
}

bool UVehicleSimulationComponent::HasOccupiedSeats() const {
    return false;
}

int32 UVehicleSimulationComponent::GetFreeSeat() {
    return 0;
}


