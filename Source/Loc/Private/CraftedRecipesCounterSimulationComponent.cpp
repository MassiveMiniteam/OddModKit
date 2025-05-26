#include "CraftedRecipesCounterSimulationComponent.h"

UCraftedRecipesCounterSimulationComponent::UCraftedRecipesCounterSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Counter = 0;
}

void UCraftedRecipesCounterSimulationComponent::OnResourceCrafted(URecipeProcessorSimulationComponent* Component, URecipeConfig* Recipe) {
}

int32 UCraftedRecipesCounterSimulationComponent::GetCount() const {
    return 0;
}


