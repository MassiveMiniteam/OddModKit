#include "PathNetwork.h"

APathNetwork::APathNetwork(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool APathNetwork::TryAddAgent(UPathNetworkAgentSimulationComponent* Agent) {
    return false;
}

void APathNetwork::RemoveAgent(UPathNetworkAgentSimulationComponent* Agent, UObject* Origin) {
}

TArray<UPathNetworkAgentSimulationComponent*> APathNetwork::GetAllAgents_Implementation() {
    return TArray<UPathNetworkAgentSimulationComponent*>();
}


