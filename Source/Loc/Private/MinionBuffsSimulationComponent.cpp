#include "MinionBuffsSimulationComponent.h"
#include "Templates/SubclassOf.h"

UMinionBuffsSimulationComponent::UMinionBuffsSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BuffInventory = NULL;
    this->MinionController = NULL;
}

void UMinionBuffsSimulationComponent::OnMinionRemoved(UMinionControllerSimulationBaseComponent* MinionControlComponent, ASimulationActor* Minion) {
}

void UMinionBuffsSimulationComponent::OnMinionAdded(UMinionControllerSimulationBaseComponent* MinionControlComponent, ASimulationActor* Minion) {
}

void UMinionBuffsSimulationComponent::OnInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item) {
}

TArray<TSubclassOf<UGameplayEffect>> UMinionBuffsSimulationComponent::GetActiveBuffs() const {
    return TArray<TSubclassOf<UGameplayEffect>>();
}


