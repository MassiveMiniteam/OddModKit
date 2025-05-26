#include "TemperatureRegulatorSimulationComponent.h"

UTemperatureRegulatorSimulationComponent::UTemperatureRegulatorSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bHeatMode = true;
}

void UTemperatureRegulatorSimulationComponent::SetHeatMode(bool bNewHeatMode) {
}

bool UTemperatureRegulatorSimulationComponent::GetHeatMode() const {
    return false;
}


