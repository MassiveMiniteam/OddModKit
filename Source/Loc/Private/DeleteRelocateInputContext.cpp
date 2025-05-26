#include "DeleteRelocateInputContext.h"

UDeleteRelocateInputContext::UDeleteRelocateInputContext() {
    this->bIsInDestructModeDrag = false;
    this->CursorInputContext = NULL;
    this->HoveredActor = NULL;
    this->RelocateAction = NULL;
    this->DeconstructInputAction = NULL;
    this->CancelInputAction = NULL;
    this->CursorType = NULL;
    this->GridIndicatorClass = NULL;
    this->GamepadMovementInputContextClass = NULL;
}



void UDeleteRelocateInputContext::OnRelocateAction(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UDeleteRelocateInputContext::OnRelocate_Implementation() {
}

void UDeleteRelocateInputContext::OnNewCellHovered_Implementation(FIntPoint Cell, FIntPoint PreviousCell) {
}





void UDeleteRelocateInputContext::OnDeconstructAction(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UDeleteRelocateInputContext::OnDeconstruct_Implementation() {
}

void UDeleteRelocateInputContext::OnCancelInput(UInputActionData* InputAction, ALocPlayerController* Player) {
}

bool UDeleteRelocateInputContext::HasCurrentlyMarkedActorsForDelete() const {
    return false;
}

UConstructionAssemblySimulationComponent* UDeleteRelocateInputContext::GetCurrentlyHoveredActor() const {
    return NULL;
}


