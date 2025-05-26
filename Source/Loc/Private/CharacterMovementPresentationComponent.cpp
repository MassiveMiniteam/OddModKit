#include "CharacterMovementPresentationComponent.h"

UCharacterMovementPresentationComponent::UCharacterMovementPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurrentMovementSpeed = 0.00f;
    this->TargetMovementSpeed = 0.00f;
    this->DistanceCharacterToGroundThreshold = 100.00f;
    this->LastRotation = 0.00f;
    this->PrevRotation = 0.00f;
    this->LocalTime = 0.00f;
    this->LastSpeed = 0.00f;
    this->PrevSpeed = 0.00f;
    this->DistanceToGround = 0.00f;
}

bool UCharacterMovementPresentationComponent::IsCloseToGround(float CustomThreshold) const {
    return false;
}


