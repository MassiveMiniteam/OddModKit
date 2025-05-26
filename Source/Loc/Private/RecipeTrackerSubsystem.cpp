#include "RecipeTrackerSubsystem.h"

URecipeTrackerSubsystem::URecipeTrackerSubsystem() {
}

void URecipeTrackerSubsystem::OnRecipeCraftedFinished(URecipeProcessorSimulationComponent* RecipeProcessorSimulationComponent, URecipeConfig* RecipeConfig) {
}

void URecipeTrackerSubsystem::OnItemCrafted(UItemConfig* ItemConfig, int32 Amount) {
}

void URecipeTrackerSubsystem::OnItemConsumed(UItemConfig* ItemConfig, int32 Amount) {
}

TArray<UItemConfig*> URecipeTrackerSubsystem::GetAllTrackedConfigs() const {
    return TArray<UItemConfig*>();
}

URecipeTrackerDataView* URecipeTrackerSubsystem::CreateDataView(UItemConfig* ItemConfig) {
    return NULL;
}


