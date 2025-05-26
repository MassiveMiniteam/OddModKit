#include "LootDropSimulationComponent.h"
#include "Templates/SubclassOf.h"

ULootDropSimulationComponent::ULootDropSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LootTable = NULL;
    this->LootAmountOnDeath = 2;
    this->LootAmountDueToDamage = 0;
    this->bLootUsesProjectileComponent = false;
    this->ProjectileFlyRadiusMin = 0;
    this->ProjectileFlyRadiusMax = 400;
}

void ULootDropSimulationComponent::OnGameplayStatChanged(UStatsComponent* StatsComp, FGameplayTag Tag, FFixed OldValue, FFixed NewValue) {
}

void ULootDropSimulationComponent::OnBeforeDespawn(UDespawnOnDeathSimulationComponent* DespawnComponent) {
}

TArray<TSubclassOf<ASimulationActor>> ULootDropSimulationComponent::GetLootForwardingActors() const {
    return TArray<TSubclassOf<ASimulationActor>>();
}

void ULootDropSimulationComponent::DropMultipleItems(int32 NumDrops) {
}


