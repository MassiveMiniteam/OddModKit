#include "TrackNetworkManagerSubsystem.h"
#include "TrackNetwork.h"
#include "TrackNetworkSimulationComponent.h"

UTrackNetworkManagerSubsystem::UTrackNetworkManagerSubsystem() {
    this->GridNetworkComponentClass = UTrackNetworkSimulationComponent::StaticClass();
    this->NetworkType = ATrackNetwork::StaticClass();
}


