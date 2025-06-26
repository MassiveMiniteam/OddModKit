#include "MapIconSimulationComponent.h"

UMapIconSimulationComponent::UMapIconSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanBePinned = false;
    this->WidgetClass = NULL;
}

void UMapIconSimulationComponent::OnMarkerShutdown(ASimulationActor* InSimulationActor, EDestructionReason Reason) {
}

void UMapIconSimulationComponent::OnInteractedFromMap_Event_Implementation(ASimulationPlayer* SimulationPlayer, EMapIconInteractionType InteractionType) {
}

bool UMapIconSimulationComponent::IsObjectCurrentlyPinnedOnMapForPlayer(ASimulationPlayer* SimulationPlayer) {
    return false;
}

void UMapIconSimulationComponent::InteractFromWorldMap(ASimulationPlayer* Player, EMapIconInteractionType InteractionType) {
}

TSoftObjectPtr<UTexture2D> UMapIconSimulationComponent::GetMapIconTexture() const {
    return NULL;
}

bool UMapIconSimulationComponent::AreAllConditionsFulfilled() const {
    return false;
}


