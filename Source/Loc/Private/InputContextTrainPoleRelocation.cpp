#include "InputContextTrainPoleRelocation.h"

UInputContextTrainPoleRelocation::UInputContextTrainPoleRelocation() {
    this->PoleForRelocation = NULL;
    this->InputContext_PolePlacement = NULL;
    this->CursorInputContext = NULL;
    this->GamepadMovementInputContext = NULL;
    this->ConstructableConfigRails = NULL;
    this->GamepadMovementInputContextClass = NULL;
    this->PolePlacementInputContextClass = NULL;
    this->CursorActorClass = NULL;
    this->GridIndicatorClass = NULL;
    this->InputAction_Place = NULL;
    this->InputAction_Cancel = NULL;
}

void UInputContextTrainPoleRelocation::OnPolePlacementContextUpdated(UInputContextTrainPolePlacement* InputContext) {
}


void UInputContextTrainPoleRelocation::OnInputAction_Place(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextTrainPoleRelocation::OnInputAction_Cancel(UInputActionData* InputAction, ALocPlayerController* Player) {
}

ASimulationActor* UInputContextTrainPoleRelocation::GetPoleForRelocation() const {
    return NULL;
}


