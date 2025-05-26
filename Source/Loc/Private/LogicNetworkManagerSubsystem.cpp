#include "LogicNetworkManagerSubsystem.h"
#include "LogicNetwork.h"
#include "LogicNetworkSimulationComponent.h"

ULogicNetworkManagerSubsystem::ULogicNetworkManagerSubsystem() {
    this->GridNetworkComponentClass = ULogicNetworkSimulationComponent::StaticClass();
    this->NetworkType = ALogicNetwork::StaticClass();
}

void ULogicNetworkManagerSubsystem::QueueNetworkForUpdate(ALogicNetwork* Network) {
}

ALogicNetwork* ULogicNetworkManagerSubsystem::FindLogicNetworkAt(FIntPoint position) {
    return NULL;
}


