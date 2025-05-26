#include "SimulationBehaviorTreeComponent.h"

USimulationBehaviorTreeComponent::USimulationBehaviorTreeComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bTickImmediately = false;
    this->bLocStopIsRequested = false;
    this->bLocIsRunning = false;
    this->bLocIsLooping = false;
}

void USimulationBehaviorTreeComponent::SetLoopMode(bool LoopMode) {
}

void USimulationBehaviorTreeComponent::RunSubTreeForIdentifier(UBehaviorTree* Tree, FName TreeIdentifier) {
}

void USimulationBehaviorTreeComponent::RunNode(UBTNode* Node) {
}

bool USimulationBehaviorTreeComponent::GetLoopMode() const {
    return false;
}

FString USimulationBehaviorTreeComponent::GetCurrentNodeName() const {
    return TEXT("");
}


