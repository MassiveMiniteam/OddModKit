#include "TimedTargetDetectorSimulationComponent.h"

UTimedTargetDetectorSimulationComponent::UTimedTargetDetectorSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TargetingClass = NULL;
}

void UTimedTargetDetectorSimulationComponent::TriggerRetargeting() {
}

FGameplayTagContainer UTimedTargetDetectorSimulationComponent::GetRequiredBiomeCellTags() {
    return FGameplayTagContainer{};
}

int32 UTimedTargetDetectorSimulationComponent::GetRadius_Implementation() {
    return 0;
}

FGameplayTagContainer UTimedTargetDetectorSimulationComponent::GetForbiddenBiomeCellTags() {
    return FGameplayTagContainer{};
}


