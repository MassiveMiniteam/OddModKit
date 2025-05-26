#include "QuestInventoryRelaySubsystem.h"

UQuestInventoryRelaySubsystem::UQuestInventoryRelaySubsystem() {
}

bool UQuestInventoryRelaySubsystem::TryConsumeItems(UQuestGiverSimulationComponent* QuestGiver, const TArray<FItemStack>& ItemsToConsume) {
    return false;
}

void UQuestInventoryRelaySubsystem::OnInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item) {
}

int32 UQuestInventoryRelaySubsystem::GetTotalItemCountForConfig(UQuestGiverSimulationComponent* QuestGiver, UItemConfig* Config) {
    return 0;
}

TArray<UInventoryComponent*> UQuestInventoryRelaySubsystem::GetInventoryRelaysForActor(ASimulationActor* SimulationActor) {
    return TArray<UInventoryComponent*>();
}

bool UQuestInventoryRelaySubsystem::CanConsumeItems(UQuestGiverSimulationComponent* QuestGiver, const TArray<FItemStack>& ItemsToConsume) {
    return false;
}


