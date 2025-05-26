#include "TrackNetworkSimulationComponent.h"

UTrackNetworkSimulationComponent::UTrackNetworkSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsCartStation = false;
    this->TargetStation = NULL;
}


