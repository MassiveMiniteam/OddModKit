#include "IncubatorSimulationComponent.h"

UIncubatorSimulationComponent::UIncubatorSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bResetOnIncubatorDone = true;
    this->RecipeSelector = NULL;
    this->bSupportInputAddon = true;
    this->CurrentAmount = 0;
    this->OutputInventory = NULL;
}

bool UIncubatorSimulationComponent::SupportsInputAddon() const {
    return false;
}

void UIncubatorSimulationComponent::ResetProgression() {
}

void UIncubatorSimulationComponent::OnSingleRecipeprocessorStatusChanged(URecipeProcessorSimulationComponent* Component, URecipeConfig* Recipe, ECraftingStatusCode ResponseCode) {
}

void UIncubatorSimulationComponent::OnRecipeChanged(USelectableRecipesSimulationComponent* Component, URecipeConfig* Recipe) {
}

void UIncubatorSimulationComponent::OnIncubationStepCompleted(UIncubationRecipeProcessorSimulationComponent* IncubationProcessor) {
}

bool UIncubatorSimulationComponent::IsCurrentlyCrafting() {
    return false;
}

int32 UIncubatorSimulationComponent::GetProgressInPercent() const {
    return 0;
}

FFixed UIncubatorSimulationComponent::GetProgress() const {
    return FFixed{};
}

TArray<UIncubationRecipeProcessorSimulationComponent*> UIncubatorSimulationComponent::GetLinkedRecipeProcessors() {
    return TArray<UIncubationRecipeProcessorSimulationComponent*>();
}

int32 UIncubatorSimulationComponent::GetCurrentAmount() const {
    return 0;
}

void UIncubatorSimulationComponent::AddAmount(int32 Amount) {
}


