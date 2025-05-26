#include "BossTokenGenerator.h"

UBossTokenGenerator::UBossTokenGenerator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ItemDecayComponent = NULL;
    this->SelectedIndex = 0;
    this->CachedBossTokenSubsystem = NULL;
}

void UBossTokenGenerator::SetSelectedIndex(int32 Index) {
}

void UBossTokenGenerator::SetBurnRateFactor(FFixed NewBurnRateFactor) {
}

void UBossTokenGenerator::OnTimerStopped(USimulationTimerComponent* SimulationTimerComponent) {
}

void UBossTokenGenerator::OnTimerStarted(USimulationTimerComponent* SimulationTimerComponent) {
}

void UBossTokenGenerator::OnItemDecayed(UItemDecayComponent* Component, UItemConfig* ItemConfig) {
}

void UBossTokenGenerator::OnDecayInventoryChanged(UItemDecayComponent* Component, UInventoryComponent* Inventory) {
}

FFixed UBossTokenGenerator::GetProcessRateFactor() const {
    return FFixed{};
}

UItemDecayComponent* UBossTokenGenerator::GetItemDecayComponent() const {
    return NULL;
}

FItemStack UBossTokenGenerator::GetCurrentlyProducedItemStack() const {
    return FItemStack{};
}


