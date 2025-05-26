#include "PathNetworkManagerSubsystem.h"
#include "PathNetworkSimulationComponent.h"

UPathNetworkManagerSubsystem::UPathNetworkManagerSubsystem() {
    this->GridNetworkComponentClass = UPathNetworkSimulationComponent::StaticClass();
}


