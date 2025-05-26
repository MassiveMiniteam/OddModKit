#include "SkeletalMeshOptimizationPresentationComponent.h"

USkeletalMeshOptimizationPresentationComponent::USkeletalMeshOptimizationPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SetOptimizationAfterSeconds = 5.00f;
    this->CurrentDuration = 0.00f;
}


