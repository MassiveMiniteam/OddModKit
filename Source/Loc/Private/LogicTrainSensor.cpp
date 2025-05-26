#include "LogicTrainSensor.h"

ULogicTrainSensor::ULogicTrainSensor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCurrentState = false;
    this->FilterInventory = NULL;
}

void ULogicTrainSensor::OnTrainReachedPole(const UTrainTracksPoleBaseSimulationComponent* Pole, const UTrainTracksAgentSimulationComponent* Agent) {
}

UTrainTracksPoleBaseSimulationComponent* ULogicTrainSensor::GetTrainPole() const {
    return NULL;
}

void ULogicTrainSensor::FindTarget() {
}


