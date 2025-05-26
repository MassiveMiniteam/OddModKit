#include "ActorOverlapSimulationComponent.h"

UActorOverlapSimulationComponent::UActorOverlapSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UActorOverlapSimulationComponent::UpdateOverlaps() {
}

void UActorOverlapSimulationComponent::OnOverlapTick_Implementation(UPositionSimulationComponent* Other, FFixed Delta) {
}

void UActorOverlapSimulationComponent::OnOverlapStopped_Implementation(UPositionSimulationComponent* Other) {
}

void UActorOverlapSimulationComponent::OnOverlapStarted_Implementation(UPositionSimulationComponent* Other) {
}

void UActorOverlapSimulationComponent::OnOverlapEvent_Native(UPositionSimulationComponent* ThisComponent, UPositionSimulationComponent* OtherComponent) {
}


