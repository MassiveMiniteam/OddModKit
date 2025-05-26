#include "DisableIfOverlappingWithAnotherGridObjectPresentationComponent.h"

UDisableIfOverlappingWithAnotherGridObjectPresentationComponent::UDisableIfOverlappingWithAnotherGridObjectPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bDisableCollision = true;
    this->bDisableRendering = false;
    this->bWasOverlapping = false;
}

void UDisableIfOverlappingWithAnotherGridObjectPresentationComponent::OnGridPositionUnderneathChanged(AGridObject* GridObject, FIntPoint GridPosition) {
}


