#include "GlobalGridNetworkTracker.h"

UGlobalGridNetworkTracker::UGlobalGridNetworkTracker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UGlobalGridNetworkTracker::OnAgentRemovedFromPathNetworkEvent(UPathNetworkAgentSimulationComponent* Agent) {
}

void UGlobalGridNetworkTracker::OnAgentAddedToPathNetworkEvent(UPathNetworkAgentSimulationComponent* Agent) {
}

UGlobalGridNetworkTracker* UGlobalGridNetworkTracker::GetGlobalAITracker(const UObject* WorldContext) {
    return NULL;
}


