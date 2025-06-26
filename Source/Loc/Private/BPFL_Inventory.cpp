#include "BPFL_Inventory.h"

UBPFL_Inventory::UBPFL_Inventory() {
}

bool UBPFL_Inventory::TryConsumeItemsInMultipleInventories(const TArray<UInventoryComponent*>& Inventories, const TArray<FItemStack>& ItemsToConsume) {
    return false;
}

bool UBPFL_Inventory::TryConsumeItemsForConstruction(ASimulationPlayer* Player, const TArray<FItemStack>& ItemsToConsume) {
    return false;
}

bool UBPFL_Inventory::PlayerCanAffordConstruction(ASimulationPlayer* Player, const TArray<FItemStack>& ConstructionCost) {
    return false;
}

bool UBPFL_Inventory::LocalPlayerCanAffordConstruction(const UObject* WorldContext, const TArray<FItemStack>& ConstructionCost) {
    return false;
}

int32 UBPFL_Inventory::HowManyTimesCanTheRequestedItemsBeConsumedDistributedOverMultipleInventories(const TArray<UInventoryComponent*>& Inventories, const TArray<FItemStack>& RequestedItems) {
    return 0;
}

int32 UBPFL_Inventory::GetAmountOfItemsForMultipleInventories(const TArray<UInventoryComponent*>& Inventories, UItemConfig* Item) {
    return 0;
}

TArray<UInventoryComponent*> UBPFL_Inventory::GetAllUsableInventoriesIncludingSpecificPlayer(ASimulationPlayer* Player) {
    return TArray<UInventoryComponent*>();
}

TArray<FItemStack> UBPFL_Inventory::GetAllItemsOfMultipleInventories(const TArray<UInventoryComponent*>& Inventories) {
    return TArray<FItemStack>();
}

TArray<UInventoryComponent*> UBPFL_Inventory::GetAllInventoriesUsableToLocalPlayerForConstruction(const UObject* WorldContext) {
    return TArray<UInventoryComponent*>();
}

bool UBPFL_Inventory::CanConsumeItemsDistributedOverMultipleInventories(const TArray<UInventoryComponent*>& Inventories, const TArray<FItemStack>& RequestedItems) {
    return false;
}


