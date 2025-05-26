#include "InputContextBuild.h"

UInputContextBuild::UInputContextBuild() {
    this->bCloseAfterPlacement = false;
    this->PresentationPreviewActor = NULL;
    this->OriginalGridObject = NULL;
    this->ConstructableConfig = NULL;
    this->InputActionPlace = NULL;
    this->InputActionRotateRight = NULL;
    this->InputActionCancel = NULL;
    this->CurrentRotation = 0.00f;
    this->bIsRelocating = false;
    this->bWaitForPlacementCommand = false;
    this->BaseInputContextClass = NULL;
    this->GridIndicatorClass = NULL;
    this->TileIndicatorClass = NULL;
    this->CursorType = NULL;
    this->GridPlacementRuleIndicatorMesh = NULL;
    this->GridPlacementRuleIndicatorMaterial = NULL;
    this->InputContextSubsystem = NULL;
    this->CursorInputContext = NULL;
    this->GamepadMovementInputContextClass = NULL;
    this->GamepadMovementInputContext = NULL;
    this->SimulationObjectDefault = NULL;
    this->GridHighlightHandler = NULL;
    this->PreviousBuiltGridObject = NULL;
}


void UInputContextBuild::SetPreviousBuiltGridObject(AGridObject* InPreviousBuiltGridObject) {
}



void UInputContextBuild::OnInputRotateRight_Implementation(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextBuild::OnInputPlace_Implementation(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextBuild::OnInputDeviceChanged(UInputDeviceMapping* InputDevice) {
}

void UInputContextBuild::OnInputCancel_Implementation(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextBuild::OnClearInputAction(UInputActionData* InputAction, ALocPlayerController* Player) {
}

bool UInputContextBuild::IsWaitingForPlacementCommand() {
    return false;
}

FGridObjectPlacementResult UInputContextBuild::GetPlacementResultCopy() {
    return FGridObjectPlacementResult{};
}

bool UInputContextBuild::CanBePlaced() {
    return false;
}


