#include "AutomaticRecipeItemSupplyComponent.h"

UAutomaticRecipeItemSupplyComponent::UAutomaticRecipeItemSupplyComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InputInventory = NULL;
    this->RecipeProcessor = NULL;
}

void UAutomaticRecipeItemSupplyComponent::OnRecipeChanged(URecipeProcessorSimulationComponent* Component, URecipeConfig* Recipe) {
}

void UAutomaticRecipeItemSupplyComponent::OnCraftingFinished(URecipeProcessorSimulationComponent* Component, URecipeConfig* Recipe) {
}


