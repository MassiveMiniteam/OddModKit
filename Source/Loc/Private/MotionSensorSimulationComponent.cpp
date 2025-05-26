#include "MotionSensorSimulationComponent.h"

UMotionSensorSimulationComponent::UMotionSensorSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bRecognizeChangeOnRemoval = true;
    this->MotionSensorResetTimer = NULL;
    this->bSignal = false;
    this->bIsInCooldownPhase = false;
}

void UMotionSensorSimulationComponent::OnMotionSensorResetTimerFired(USimulationTimerComponent* SimulationTimerComponent) {
}


