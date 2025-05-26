#include "InputContextTerraform.h"

UInputContextTerraform::UInputContextTerraform() {
    this->PlacementRadiusIndication = 500;
    this->bDigUp = false;
    this->UpdateIndicationDelay = 0.00f;
    this->InputActionPlace = NULL;
    this->InputActionChangeMode = NULL;
    this->InputActionCancel = NULL;
    this->ConstructableConfig = NULL;
    this->GridHighlightHandler_Terraform = NULL;
    this->GridHighlightHandler_Hover_Valid = NULL;
    this->GridHighlightHandler_Hover_Invalid = NULL;
    this->GridIndicatorClass = NULL;
    this->CursorType = NULL;
    this->GridPlacementRuleIndicatorMesh_Terraform_Up = NULL;
    this->GridPlacementRuleIndicatorMesh_Terraform_Down = NULL;
    this->GridPlacementRuleIndicatorMaterial_Terraform_Up = NULL;
    this->GridPlacementRuleIndicatorMaterial_Terraform_Down = NULL;
    this->GridPlacementRuleIndicatorMesh_Hover_Valid = NULL;
    this->GridPlacementRuleIndicatorMaterial_Hover_Valid = NULL;
    this->GridPlacementRuleIndicatorMesh_Hover_Invalid = NULL;
    this->GridPlacementRuleIndicatorMaterial_Hover_Invalid = NULL;
    this->InputContextSubsystem = NULL;
    this->CursorInputContext = NULL;
    this->GamepadMovementInputContextClass = NULL;
    this->GamepadMovementInputContext = NULL;
}


void UInputContextTerraform::OnInputPlace_Implementation(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextTerraform::OnInputDeviceChanged(UInputDeviceMapping* InputDevice) {
}

void UInputContextTerraform::OnInputChangeMode_Implementation(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextTerraform::OnInputCancel_Implementation(UInputActionData* InputAction, ALocPlayerController* Player) {
}





