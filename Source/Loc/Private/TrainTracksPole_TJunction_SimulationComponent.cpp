#include "TrainTracksPole_TJunction_SimulationComponent.h"
#include "TrainCondition_HasAnyCommonItem.h"
#include "TrainCondition_HasAnyCommonItem_OrEmpty.h"

UTrainTracksPole_TJunction_SimulationComponent::UTrainTracksPole_TJunction_SimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->JunctionCondition = UTrainCondition_HasAnyCommonItem::StaticClass();
    this->SensorCondition = UTrainCondition_HasAnyCommonItem_OrEmpty::StaticClass();
    this->LogicInput = NULL;
    this->LogicOutput = NULL;
    this->SensorSignalSendDelayTimer = NULL;
}

void UTrainTracksPole_TJunction_SimulationComponent::OnSensorDelayTimerFired(USimulationTimerComponent* SimulationTimerComponent) {
}


