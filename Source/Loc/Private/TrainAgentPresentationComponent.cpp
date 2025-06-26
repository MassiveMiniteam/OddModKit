#include "TrainAgentPresentationComponent.h"

UTrainAgentPresentationComponent::UTrainAgentPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->WheelRotationAnglePerCentiMeterTravelled = 0.00f;
    this->AudioComponent = NULL;
}


