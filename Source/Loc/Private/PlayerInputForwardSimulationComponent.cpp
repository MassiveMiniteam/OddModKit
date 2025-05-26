#include "PlayerInputForwardSimulationComponent.h"

UPlayerInputForwardSimulationComponent::UPlayerInputForwardSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UPlayerInputForwardSimulationComponent::OverWriteInputTags(const FGameplayTagContainer& NewTags) {
}

bool UPlayerInputForwardSimulationComponent::HasCurrentlyTag(const FGameplayTag& Tag) const {
    return false;
}


