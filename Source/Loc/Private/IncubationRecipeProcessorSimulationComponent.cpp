#include "IncubationRecipeProcessorSimulationComponent.h"

UIncubationRecipeProcessorSimulationComponent::UIncubationRecipeProcessorSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MyPositionComponent = NULL;
    this->MyAssemblyComponent = NULL;
    this->bCanSupportExternalIncubator = false;
}

void UIncubationRecipeProcessorSimulationComponent::OnRelocate(UPositionSimulationComponent* PositionComponent, FIntPoint LastGridPosition) {
}

void UIncubationRecipeProcessorSimulationComponent::OnIncubatorRecipeChanged(USelectableRecipesSimulationComponent* RecipeSelector) {
}

void UIncubationRecipeProcessorSimulationComponent::OnDisassemble(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer) {
}

UIncubatorSimulationComponent* UIncubationRecipeProcessorSimulationComponent::GetIncubator() const {
    return NULL;
}


