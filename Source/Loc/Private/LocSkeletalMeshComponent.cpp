#include "LocSkeletalMeshComponent.h"

ULocSkeletalMeshComponent::ULocSkeletalMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseAggregatedTick = false;
    this->AggregatedPhaseCounts = 2;
}


