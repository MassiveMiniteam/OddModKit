#include "RecipeProcessorEfficiencyModifierSimulationComponent.h"

URecipeProcessorEfficiencyModifierSimulationComponent::URecipeProcessorEfficiencyModifierSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MinT = 0;
    this->MaxT = 10000;
    this->CountUntilTIncrements = 10;
    this->RecipeProcessor = NULL;
    this->MyPositionComponent = NULL;
    this->AssemlyComponent = NULL;
    this->StatsComponent = NULL;
}

void URecipeProcessorEfficiencyModifierSimulationComponent::OnPositionChanged(UPositionSimulationComponent* PositionComponent, FIntVector LastPosition) {
}

void URecipeProcessorEfficiencyModifierSimulationComponent::OnGridCellChanged(FIntPoint GridPosition) {
}

void URecipeProcessorEfficiencyModifierSimulationComponent::OnDisassemble(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer) {
}

void URecipeProcessorEfficiencyModifierSimulationComponent::OnCrafedRecipesAmountChanged(UCraftedRecipesCounterSimulationComponent* Component, int64 Value) {
}

void URecipeProcessorEfficiencyModifierSimulationComponent::LogDebugValues(int32 From, int32 To) {
}

FFixed URecipeProcessorEfficiencyModifierSimulationComponent::GetPercentage() {
    return FFixed{};
}

FFixed URecipeProcessorEfficiencyModifierSimulationComponent::GetCurrentValue() {
    return FFixed{};
}

FFixed URecipeProcessorEfficiencyModifierSimulationComponent::CalculateValue(int32 Count) {
    return FFixed{};
}

int32 URecipeProcessorEfficiencyModifierSimulationComponent::CalculateT(int32 Count) {
    return 0;
}


