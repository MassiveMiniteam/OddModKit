#include "MinionAssignCursorSnapPresentationComponent.h"

UMinionAssignCursorSnapPresentationComponent::UMinionAssignCursorSnapPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SnapPositionSceneComponent = NULL;
}

bool UMinionAssignCursorSnapPresentationComponent::ShouldSnapToActiveMinion_Implementation() {
    return false;
}

FVector UMinionAssignCursorSnapPresentationComponent::GetSnapPosition() {
    return FVector{};
}


