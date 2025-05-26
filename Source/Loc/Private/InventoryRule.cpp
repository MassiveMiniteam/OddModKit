#include "InventoryRule.h"

UInventoryRule::UInventoryRule() {
    this->Precondition = NULL;
}

int32 UInventoryRule::OverrideStackSize_Implementation(UInventoryComponent* Inventory, UItemConfig* Config, int32 DefaultStackSize, int32 Index, UItemStackData* Data) {
    return 0;
}

int32 UInventoryRule::ModifyAmount_Remove_Implementation(UInventoryComponent* Inventory, UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data) {
    return 0;
}

int32 UInventoryRule::ModifyAmount_Add_Implementation(UInventoryComponent* Inventory, UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data) {
    return 0;
}

bool UInventoryRule::IsActive(const UObject* WorldContext) {
    return false;
}

bool UInventoryRule::CanRemoveItemAt_Implementation(UInventoryComponent* Inventory, UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data) {
    return false;
}

bool UInventoryRule::CanAddItemAt_Implementation(UInventoryComponent* Inventory, UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data) {
    return false;
}


