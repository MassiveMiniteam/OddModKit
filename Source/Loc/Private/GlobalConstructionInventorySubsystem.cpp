#include "GlobalConstructionInventorySubsystem.h"

UGlobalConstructionInventorySubsystem::UGlobalConstructionInventorySubsystem() {
}

TArray<FItemStack> UGlobalConstructionInventorySubsystem::GetAllItems() const {
    return TArray<FItemStack>();
}

TArray<UInventoryComponent*> UGlobalConstructionInventorySubsystem::GetAllInventoriesIncludingSpecificPlayer(UInventoryComponent* PlayerInventory) const {
    return TArray<UInventoryComponent*>();
}

TArray<UInventoryComponent*> UGlobalConstructionInventorySubsystem::GetAllInventoriesIncludingLocalPlayer() const {
    return TArray<UInventoryComponent*>();
}

TArray<UInventoryComponent*> UGlobalConstructionInventorySubsystem::GetAllInventories() const {
    return TArray<UInventoryComponent*>();
}


