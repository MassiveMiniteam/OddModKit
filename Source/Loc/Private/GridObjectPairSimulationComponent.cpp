#include "GridObjectPairSimulationComponent.h"

UGridObjectPairSimulationComponent::UGridObjectPairSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UGridObjectPairSimulationComponent::SetRelatedGridObject(AGridObject* GridObject) {
}

FFloatInterval UGridObjectPairSimulationComponent::GetRequiredDistanceToRelatedActor() const {
    return FFloatInterval{};
}

AGridObject* UGridObjectPairSimulationComponent::GetRelatedGridObject() const {
    return NULL;
}


