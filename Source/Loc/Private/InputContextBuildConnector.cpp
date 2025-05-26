#include "InputContextBuildConnector.h"

UInputContextBuildConnector::UInputContextBuildConnector() {
    this->CursorInputContext = NULL;
    this->GamepadMovementInputContext = NULL;
    this->InputContext_PolePlacement = NULL;
    this->ConstructableConfigRails = NULL;
    this->ConstructableConfigPole = NULL;
    this->PreviewPresentationActor_Rail = NULL;
    this->CachedHoveredRail = NULL;
    this->CachedHoveredPole = NULL;
    this->bWaitForPlacementCommand = false;
    this->InputAction_Place = NULL;
    this->InputAction_Cancel = NULL;
    this->InputAction_Destroy = NULL;
    this->GamepadMovementInputContextClass = NULL;
    this->PolePlacementInputContextClass = NULL;
    this->CursorActorClass = NULL;
    this->GridIndicatorClass = NULL;
    this->MouseHitSphereRadius = 200.00f;
}

void UInputContextBuildConnector::OnPolePlacementContextUpdated(UInputContextTrainPolePlacement* InputContext) {
}





void UInputContextBuildConnector::OnInputAction_Place(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextBuildConnector::OnInputAction_Destroy(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextBuildConnector::OnInputAction_Cancel(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextBuildConnector::NotifyConnectionChange(FTrainsConnectionChangeDelegateParams ConnectionChangeParams) {
}

ASimulationActor* UInputContextBuildConnector::GetHoveredRailSimulation() const {
    return NULL;
}

UTrainTracksPoleBaseSimulationComponent* UInputContextBuildConnector::GetHoveredPoleSimulationComponent() const {
    return NULL;
}

ASimulationActor* UInputContextBuildConnector::GetHoveredPoleSimulationActor() const {
    return NULL;
}



