#include "LogicNetworkSimulationComponent.h"

ULogicNetworkSimulationComponent::ULogicNetworkSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BitMask = 1;
}

void ULogicNetworkSimulationComponent::NotifyAboutSignalChange(ALogicNetwork* Network) {
}

bool ULogicNetworkSimulationComponent::IsConnectedToLogicNetworkComponent(ULogicNetworkSimulationComponent* OtherLogicNetworkComponent) {
    return false;
}

bool ULogicNetworkSimulationComponent::GetLogicNetworkState() {
    return false;
}

ALogicNetwork* ULogicNetworkSimulationComponent::GetLogicNetwork() {
    return NULL;
}


