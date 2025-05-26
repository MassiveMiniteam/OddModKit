#include "InteractionPresentationComponent.h"

UInteractionPresentationComponent::UInteractionPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bPrimaryInteractionEnabled = true;
    this->bSecondaryInteractionEnabled = true;
    this->PrimaryCurrentlyDisabledUITreatment = EInteractionCurrentlyDisabledUITreatment::GreyOut;
    this->SecondaryCurrentlyDisabledUITreatment = EInteractionCurrentlyDisabledUITreatment::GreyOut;
    this->bCurrentlyBeingLookedAt = false;
    this->bCurrentlyBeingHovered = false;
    this->bOutlineOnHover = true;
    this->bOutlineOnLookedAt = true;
    this->bAlsoOutlineChildActors = true;
    this->bHighlightOnHover = false;
    this->bHighlightOnLookedAt = false;
}

void UInteractionPresentationComponent::SetOutlineEnabled(bool bOutlineIsCurrentlyActive, FName SourceTag) {
}

void UInteractionPresentationComponent::SetLookAtState(bool bState) {
}

void UInteractionPresentationComponent::SetHoverState(bool bHoverState) {
}

bool UInteractionPresentationComponent::IsSecondaryInteractionPossible() const {
    return false;
}

bool UInteractionPresentationComponent::IsSecondaryInteractionGenerallyPossible() const {
    return false;
}

bool UInteractionPresentationComponent::IsSecondaryInteractionCurrentlyPossible() const {
    return false;
}

bool UInteractionPresentationComponent::IsPrimaryInteractionPossible() const {
    return false;
}

bool UInteractionPresentationComponent::IsPrimaryInteractionGenerallyPossible() const {
    return false;
}

bool UInteractionPresentationComponent::IsPrimaryInteractionCurrentlyPossible() const {
    return false;
}

bool UInteractionPresentationComponent::IsPlayerInInteractionRangeForMouse_Secondary() const {
    return false;
}

bool UInteractionPresentationComponent::IsPlayerInInteractionRangeForMouse_Primary() const {
    return false;
}

bool UInteractionPresentationComponent::IsAnyInteractionPossible() const {
    return false;
}

void UInteractionPresentationComponent::CallSecondaryAction() {
}

void UInteractionPresentationComponent::CallPrimaryActionIgnoreCondition() {
}

void UInteractionPresentationComponent::CallPrimaryAction() {
}


