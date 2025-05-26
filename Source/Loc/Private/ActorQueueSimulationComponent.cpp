#include "ActorQueueSimulationComponent.h"

UActorQueueSimulationComponent::UActorQueueSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SizeLimit = 5;
    this->bBindPositionAttachmentToQueuePosition = false;
}

void UActorQueueSimulationComponent::RemoveFromQueue(ASimulationActor* Actor) {
}

void UActorQueueSimulationComponent::OnActorShutdown(ASimulationActor* Actor, EDestructionReason Reason) {
}

bool UActorQueueSimulationComponent::IsInQueue(ASimulationActor* Actor) const {
    return false;
}

bool UActorQueueSimulationComponent::HasFirstSpotInQueue(ASimulationActor* Actor) const {
    return false;
}

TArray<ASimulationActor*> UActorQueueSimulationComponent::GetQueuedActors() const {
    return TArray<ASimulationActor*>();
}

int32 UActorQueueSimulationComponent::GetNumQueuedActors() const {
    return 0;
}

int32 UActorQueueSimulationComponent::GetActorIndexInQueue(ASimulationActor* Actor) const {
    return 0;
}

bool UActorQueueSimulationComponent::CanRemoveActorFromQueue(ASimulationActor* Actor) const {
    return false;
}

bool UActorQueueSimulationComponent::CanAddActorToQueue(ASimulationActor* Actor) const {
    return false;
}

void UActorQueueSimulationComponent::AddToQueue(ASimulationActor* Actor) {
}


