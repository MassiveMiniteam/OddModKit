#include "MovementAnimationPresentationComponent.h"

UMovementAnimationPresentationComponent::UMovementAnimationPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseAggregatedTick = true;
    this->LastMovementSpeed = 0;
    this->LastRotationSign = 0;
    this->bUseGridNetworkAgentInsteadOfUnitMovement = false;
}


