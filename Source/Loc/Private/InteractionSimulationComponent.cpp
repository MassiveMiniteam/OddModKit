#include "InteractionSimulationComponent.h"

UInteractionSimulationComponent::UInteractionSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UInteractionSimulationComponent::RemoveInteractionPlayer(ASimulationPlayer* Player) {
}

bool UInteractionSimulationComponent::IsInUse() const {
    return false;
}

bool UInteractionSimulationComponent::IsCurrentlyOccupied() const {
    return false;
}

TArray<ASimulationPlayer*> UInteractionSimulationComponent::GetCurrentInteractingPlayers() const {
    return TArray<ASimulationPlayer*>();
}

void UInteractionSimulationComponent::AddInteractionPlayer(FPlayerInteractionData Player) {
}


