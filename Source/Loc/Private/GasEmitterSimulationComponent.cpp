#include "GasEmitterSimulationComponent.h"

UGasEmitterSimulationComponent::UGasEmitterSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GasItemConfig = NULL;
    this->PositionComponent = NULL;
}

void UGasEmitterSimulationComponent::StopEmitter() {
}

void UGasEmitterSimulationComponent::StartEmitter() {
}


