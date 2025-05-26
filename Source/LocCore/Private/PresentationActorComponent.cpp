#include "PresentationActorComponent.h"

UPresentationActorComponent::UPresentationActorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseAggregatedTick = false;
    this->AggregatedPhaseCounts = 2;
}

void UPresentationActorComponent::OnPresentationPreBegin_Implementation(bool bIsLoading) {
}

void UPresentationActorComponent::OnPresentationEnd_Implementation(EDestructionReason Reason) {
}

void UPresentationActorComponent::OnPresentationBegin_Implementation(bool bIsLoading) {
}

ASimulationActor* UPresentationActorComponent::GetSimulationActor() const {
    return NULL;
}


