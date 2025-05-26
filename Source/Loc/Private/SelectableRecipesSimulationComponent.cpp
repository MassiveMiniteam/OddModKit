#include "SelectableRecipesSimulationComponent.h"

USelectableRecipesSimulationComponent::USelectableRecipesSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseAllRecipes = false;
    this->CurrentSelectedRecipe = NULL;
    this->DefaultRecipe = NULL;
}

void USelectableRecipesSimulationComponent::SetRecipe(URecipeConfig* InRecipe) {
}

bool USelectableRecipesSimulationComponent::IsSelectedRecipeValid() const {
    return false;
}

URecipeConfig* USelectableRecipesSimulationComponent::GetSelectedRecipe() const {
    return NULL;
}

URecipeConfig* USelectableRecipesSimulationComponent::GetDefaultRecipe() const {
    return NULL;
}

TArray<URecipeConfig*> USelectableRecipesSimulationComponent::GetAvailableRecipes() const {
    return TArray<URecipeConfig*>();
}

void USelectableRecipesSimulationComponent::AutoSelectRecipeIfThereIsOnlyOne() {
}


