#include "StepSensorSimulationComponent.h"

UStepSensorSimulationComponent::UStepSensorSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LogicOutput = NULL;
    this->Grid = NULL;
    this->bIsPressedDown = false;
}

bool UStepSensorSimulationComponent::GetIsPressedDown() const {
    return false;
}


