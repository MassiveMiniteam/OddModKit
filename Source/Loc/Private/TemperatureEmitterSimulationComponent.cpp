#include "TemperatureEmitterSimulationComponent.h"

UTemperatureEmitterSimulationComponent::UTemperatureEmitterSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EmittedTemperature = 0;
    this->Radius = 1000;
}

void UTemperatureEmitterSimulationComponent::SetEmittedTemperature(int32 NewTemperatureValue) {
}

int32 UTemperatureEmitterSimulationComponent::GetRadius() const {
    return 0;
}

int32 UTemperatureEmitterSimulationComponent::GetEmittedTemperature() const {
    return 0;
}


