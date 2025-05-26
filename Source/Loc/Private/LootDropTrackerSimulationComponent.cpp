#include "LootDropTrackerSimulationComponent.h"
#include "Templates/SubclassOf.h"

ULootDropTrackerSimulationComponent::ULootDropTrackerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void ULootDropTrackerSimulationComponent::UnlockDropsFor(TSubclassOf<ASimulationActor> ActorClass) {
}

void ULootDropTrackerSimulationComponent::OnLootDropped(ULootDropSimulationComponent* LootDropComponent, FItemStack Item) {
}

ULootDropTrackerSimulationComponent* ULootDropTrackerSimulationComponent::GetLootDropTracker(UObject* WorldContext) {
    return NULL;
}

FTrackedLootData ULootDropTrackerSimulationComponent::GetLootDataForActorType(TSubclassOf<AActor> ActorClass) {
    return FTrackedLootData{};
}


