#include "TeleporterSimulationComponent.h"

UTeleporterSimulationComponent::UTeleporterSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
    this->TeleporterStrategy = NULL;
    this->bShowLoadingScreen = true;
    this->bBindMapIconComponent = true;
}

void UTeleporterSimulationComponent::TeleportLocalPlayerCharacterToThis() {
}

void UTeleporterSimulationComponent::OnInteractedWithMapIcon(UMapIconSimulationComponent* MapIcon, ASimulationPlayer* Player, EMapIconInteractionType InteractionType) {
}

FText UTeleporterSimulationComponent::GetStatusText() const {
    return FText::GetEmpty();
}

bool UTeleporterSimulationComponent::CanBeUsed() const {
    return false;
}


