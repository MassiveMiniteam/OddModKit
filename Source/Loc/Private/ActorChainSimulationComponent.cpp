#include "ActorChainSimulationComponent.h"

UActorChainSimulationComponent::UActorChainSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UActorChainSimulationComponent::IsLast() const {
    return false;
}

bool UActorChainSimulationComponent::IsInFirstHalf() const {
    return false;
}

bool UActorChainSimulationComponent::IsFirst() const {
    return false;
}

bool UActorChainSimulationComponent::HasPrevious() const {
    return false;
}

bool UActorChainSimulationComponent::HasNext() const {
    return false;
}

UActorChainSimulationComponent* UActorChainSimulationComponent::GetPrevious() const {
    return NULL;
}

UActorChainSimulationComponent* UActorChainSimulationComponent::GetNext() const {
    return NULL;
}

UActorChainSimulationComponent* UActorChainSimulationComponent::GetLastActor() const {
    return NULL;
}

UActorChainSimulationComponent* UActorChainSimulationComponent::GetFirstActor() const {
    return NULL;
}

TArray<UActorChainSimulationComponent*> UActorChainSimulationComponent::GetCompleteChainAsSortedArray() const {
    return TArray<UActorChainSimulationComponent*>();
}

void UActorChainSimulationComponent::AttachInFrontOf(UActorChainSimulationComponent* Other) {
}

void UActorChainSimulationComponent::AttachBehind(UActorChainSimulationComponent* Other) {
}


