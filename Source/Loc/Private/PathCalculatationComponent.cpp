#include "PathCalculatationComponent.h"

UPathCalculatationComponent::UPathCalculatationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PathFinderComponent = NULL;
}

void UPathCalculatationComponent::OnPathCalculated(UPathFinderComponent* InPathFinderComponent, EPathFindingRequestResult Result, UPathFindingRequest* Path, FIntVector TargetPosition) {
}

void UPathCalculatationComponent::CalculatePath(FIntVector TargetLocation) {
}


