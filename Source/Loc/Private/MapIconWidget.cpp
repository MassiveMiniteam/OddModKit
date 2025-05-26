#include "MapIconWidget.h"

UMapIconWidget::UMapIconWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->OutOfScreenMarkerRotationAngle = 0.00f;
    this->bWidgetIsOutOfScreen = false;
    this->bIsMinimapIcon = false;
    this->ImageIcon = NULL;
    this->OutOfScreenMarker = NULL;
    this->bClampPositionToViewport = false;
}

void UMapIconWidget::UpdateVisibilityByZoomLevel(int32 NewZoomLevel) {
}

void UMapIconWidget::Unhover() {
}

bool UMapIconWidget::ShouldClampPositionToViewport_Implementation(ASimulationPlayer* SimulationPlayer) {
    return false;
}


void UMapIconWidget::OnWorldPositionChanged(UPositionSimulationComponent* PositionComponent, FIntVector LastPosition) {
}


void UMapIconWidget::OnSimulationActorShutDown(ASimulationActor* SimulationActor, EDestructionReason Reason) {
}


void UMapIconWidget::OnPinnedStateChanged(bool bObjectIsPinned, ASimulationPlayer* SimulationPlayer) {
}

void UMapIconWidget::OnMapIconLoaded() {
}

void UMapIconWidget::OnInteractedFromMap_Implementation(ASimulationPlayer* SimulationPlayer, EMapIconInteractionType InteractionType) {
}


void UMapIconWidget::InteractFromMap(ASimulationPlayer* SimulationPlayer, EMapIconInteractionType InteractionType) {
}

void UMapIconWidget::Hover() {
}


