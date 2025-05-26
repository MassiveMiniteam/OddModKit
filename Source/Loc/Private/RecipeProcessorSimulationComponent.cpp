#include "RecipeProcessorSimulationComponent.h"

URecipeProcessorSimulationComponent::URecipeProcessorSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanEverTick = true;
}

void URecipeProcessorSimulationComponent::SetRecipe(URecipeConfig* InRecipe) {
}

void URecipeProcessorSimulationComponent::SetInputInventory(UInventoryComponent* InputInventoryIn) {
}

void URecipeProcessorSimulationComponent::OnRecipeChanged_Internal(USelectableRecipesSimulationComponent* Component, URecipeConfig* Config) {
}

void URecipeProcessorSimulationComponent::OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem) {
}

bool URecipeProcessorSimulationComponent::IsCurrentRecipeValid() const {
    return false;
}

bool URecipeProcessorSimulationComponent::IsCraftingPossible() const {
    return false;
}

URecipeConfig* URecipeProcessorSimulationComponent::GetRecipe() const {
    return NULL;
}

ECraftingStatusCode URecipeProcessorSimulationComponent::GetCurrentStatusCode() const {
    return ECraftingStatusCode::Processing;
}

FFixed URecipeProcessorSimulationComponent::GetCurrentProductionRate() const {
    return FFixed{};
}

FFixed URecipeProcessorSimulationComponent::GetCurrentCraftingProgressPercent() const {
    return FFixed{};
}


