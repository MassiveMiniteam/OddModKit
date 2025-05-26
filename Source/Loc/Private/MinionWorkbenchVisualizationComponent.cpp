#include "MinionWorkbenchVisualizationComponent.h"

UMinionWorkbenchVisualizationComponent::UMinionWorkbenchVisualizationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseAggregatedTick = true;
    this->MinionInventory = NULL;
    this->RecipeProcessor = NULL;
}

void UMinionWorkbenchVisualizationComponent::OnWorkSlotChanged_Implementation(UManpowerSimulationComponent* ManpowerSimulationComponent, int32 Slot) {
}

void UMinionWorkbenchVisualizationComponent::OnInventorySlotChanged(int32 Slot) {
}

void UMinionWorkbenchVisualizationComponent::OnCraftingProcessChanged_Event_Implementation(URecipeProcessorSimulationComponent* Component, URecipeConfig* Recipe, ECraftingStatusCode ResponseCode) {
}

void UMinionWorkbenchVisualizationComponent::MinionInventorySlotChanged_Event_Implementation(int32 Slot) {
}

FTransform UMinionWorkbenchVisualizationComponent::GetWorldTransformForMinion(FMinionWorkbenchConfig WorkbenchConfig, float DistanceOffsetToWorkstation) {
    return FTransform{};
}

FTransform UMinionWorkbenchVisualizationComponent::GetTransformForWorkbench(FMinionWorkbenchConfig WorkbenchConfig) {
    return FTransform{};
}

FTransform UMinionWorkbenchVisualizationComponent::GetRelativeTransformForMinion(FMinionWorkbenchConfig WorkbenchConfig) {
    return FTransform{};
}

UItemMinionConfig* UMinionWorkbenchVisualizationComponent::GetMinionConfigAtInventoryIndex(int32 InventoryIndex) {
    return NULL;
}

bool UMinionWorkbenchVisualizationComponent::bHasPlayerControlledMinions() {
    return false;
}


