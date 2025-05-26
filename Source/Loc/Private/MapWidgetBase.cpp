#include "MapWidgetBase.h"

UMapWidgetBase::UMapWidgetBase() {
    this->PlayerMarkerWidgetClass = NULL;
    this->DefaultMapSize = 1280.00f;
    this->ZoomMin = 2.00f;
    this->ZoomMax = 15.00f;
    this->ZoomFactor = 6.00f;
    this->OffscreenIconsScreenBorderDistance = 150.00f;
}

void UMapWidgetBase::UpdateWidgetPositionOnMap(UMapIconWidget* MapIconWidget, FIntVector WorldPosition, U2DScrollBox* MapScrollBox) {
}


void UMapWidgetBase::UpdateGenericIconPositions_Native_Implementation(bool bOnlyIfClampingToViewportIsNeeded, U2DScrollBox* MapScrollBox) {
}

void UMapWidgetBase::UnregisterIcons() {
}



void UMapWidgetBase::RegisterAndAddIcons() {
}

void UMapWidgetBase::OnMapIconComponentUnregistered(UComponentRegistrationSubsystem* Subsystem, URegisteredSimulationComponent* Component) {
}

void UMapWidgetBase::OnMapIconComponentRegistered(UComponentRegistrationSubsystem* Subsystem, URegisteredSimulationComponent* Component) {
}



