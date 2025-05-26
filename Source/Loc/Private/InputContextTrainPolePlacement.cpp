#include "InputContextTrainPolePlacement.h"

UInputContextTrainPolePlacement::UInputContextTrainPolePlacement() {
    this->InputAction_RotateRight = NULL;
    this->InputAction_SizeUp = NULL;
    this->InputAction_SizeDown = NULL;
    this->ConstructableConfigPole = NULL;
    this->PreviewSimulationActor = NULL;
    this->PreviewPresentationActor = NULL;
    this->CursorInputContext = NULL;
}

bool UInputContextTrainPolePlacement::PoleFulfillsPlacementRules(ASimulationActor* IgnoreActor) const {
    return false;
}



void UInputContextTrainPolePlacement::OnInputAction_SizeUp(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextTrainPolePlacement::OnInputAction_SizeDown(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextTrainPolePlacement::OnInputAction_Rotate(UInputActionData* InputAction, ALocPlayerController* Player) {
}

APresentationActor* UInputContextTrainPolePlacement::GetPreviewPresentationActor() const {
    return NULL;
}

float UInputContextTrainPolePlacement::GetCurrentTargetRotation() const {
    return 0.0f;
}

int32 UInputContextTrainPolePlacement::GetCurrentHeight() const {
    return 0;
}


