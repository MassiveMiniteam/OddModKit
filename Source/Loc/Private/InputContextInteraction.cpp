#include "InputContextInteraction.h"

UInputContextInteraction::UInputContextInteraction() {
    this->PrimaryAction = NULL;
    this->SecondaryAction = NULL;
}

void UInputContextInteraction::UseCustomSphereTraceLocations(const FVector& Start, const FVector& End, float Radius) {
}

void UInputContextInteraction::UnsubscribeFromLastInteractedPresentationComponent() {
}

void UInputContextInteraction::SetCurrentInteractionComponent(UInteractionPresentationComponent* Component) {
}



void UInputContextInteraction::DisableCustomSphereTraceLocations() {
}

void UInputContextInteraction::CallSecondaryAction(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextInteraction::CallPrimaryAction(UInputActionData* InputAction, ALocPlayerController* Player) {
}


