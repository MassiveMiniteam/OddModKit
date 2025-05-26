#include "VisibilityStatePresentationComponent.h"

UVisibilityStatePresentationComponent::UVisibilityStatePresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurrentState = Static;
}

void UVisibilityStatePresentationComponent::SetState(TEnumAsByte<EVisibilityState> NewState) {
}


