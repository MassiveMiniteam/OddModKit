#include "ManpowerSimulationComponent.h"

UManpowerSimulationComponent::UManpowerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MaxAllowedCraftingPlayers = 1;
}

void UManpowerSimulationComponent::UpdateManpower() {
}

void UManpowerSimulationComponent::RemoveCraftingPlayer(ASimulationPlayer* Player) {
}

void UManpowerSimulationComponent::OnStatChanged(UStatsComponent* StatsComponentIn, FGameplayTag Tag, FFixed OldValue, FFixed NewValue) {
}

void UManpowerSimulationComponent::OnSlotChanged(int32 SlotIndex) {
}

void UManpowerSimulationComponent::OnLogicInputChanged(ULogicConnectionSimulationComponent* Input) {
}

void UManpowerSimulationComponent::OnItemAdded(UItemConfig* Config, int32 Amount, UObject* Origin) {
}

bool UManpowerSimulationComponent::IsWorkerSlotEnabled(int32 Index) const {
    return false;
}

bool UManpowerSimulationComponent::IsWorkerSlotConnectedToLogic(int32 Index) const {
    return false;
}

bool UManpowerSimulationComponent::IsSlotReadyToWork(int32 SlotIndex) const {
    return false;
}

int32 UManpowerSimulationComponent::GetNumberOfWorkingSlots() const {
    return 0;
}

ULogicConnectionSimulationComponent* UManpowerSimulationComponent::GetLogicConnectionForSlot(int32 Index) const {
    return NULL;
}

TArray<ASimulationPlayer*> UManpowerSimulationComponent::GetCurrentlyCraftingPlayers() {
    return TArray<ASimulationPlayer*>();
}

void UManpowerSimulationComponent::AddCraftingPlayer(ASimulationPlayer* Player) {
}


