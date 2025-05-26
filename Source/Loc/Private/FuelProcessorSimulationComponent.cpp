#include "FuelProcessorSimulationComponent.h"

UFuelProcessorSimulationComponent::UFuelProcessorSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ItemDecayComponent = NULL;
    this->LastFuelConfig = NULL;
}

void UFuelProcessorSimulationComponent::SetBurnRateFactor(FFixed NewBurnRateFactor) {
}

void UFuelProcessorSimulationComponent::OnItemDecayed(UItemDecayComponent* Component, UItemConfig* ItemConfig) {
}

void UFuelProcessorSimulationComponent::OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem) {
}

void UFuelProcessorSimulationComponent::OnDecayInventoryChanged(UItemDecayComponent* Component, UInventoryComponent* Inventory) {
}

UItemDecayComponent* UFuelProcessorSimulationComponent::GetItemDecayComponent() const {
    return NULL;
}

FFixed UFuelProcessorSimulationComponent::GetBurnRateFactor() const {
    return FFixed{};
}


