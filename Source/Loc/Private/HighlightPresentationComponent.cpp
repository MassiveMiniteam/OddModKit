#include "HighlightPresentationComponent.h"

UHighlightPresentationComponent::UHighlightPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnableOnBeginPlay = true;
    this->bEnableOnPresentationBegin = false;
}



bool UHighlightPresentationComponent::IsCurrentlyHighlighted() const {
    return false;
}

void UHighlightPresentationComponent::EnableHighlight(bool bState) {
}


