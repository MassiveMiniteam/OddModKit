#include "CraftingIndicatorPresentationComponent.h"

UCraftingIndicatorPresentationComponent::UCraftingIndicatorPresentationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UCraftingIndicatorPresentationComponent::OnCraftingStatusChanged_Implementation(URecipeProcessorSimulationComponent* InRecipeProcessorComponent, URecipeConfig* Recipe, ECraftingStatusCode CraftingResponse) {
}


