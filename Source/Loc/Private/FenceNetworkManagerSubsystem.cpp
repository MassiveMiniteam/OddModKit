#include "FenceNetworkManagerSubsystem.h"
#include "FenceNetwork.h"
#include "FenceNetworkSimulationComponent.h"

UFenceNetworkManagerSubsystem::UFenceNetworkManagerSubsystem() {
    this->GridNetworkComponentClass = UFenceNetworkSimulationComponent::StaticClass();
    this->NetworkType = AFenceNetwork::StaticClass();
}


