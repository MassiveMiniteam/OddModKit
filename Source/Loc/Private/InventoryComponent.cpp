#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bOverflowAllowed = true;
    this->bDeleteInsteadOfSwap = false;
    this->DefaultNumSlots = 0;
    this->Items.AddDefaulted(1);
    this->bAddDefaultRules = true;
    this->bIsInFirstPredictionTransfer = false;
}

bool UInventoryComponent::TryToConsumeItems(const TArray<FItemStack>& ItemsToConsume, UObject* Origin) {
    return false;
}

bool UInventoryComponent::TryToConsumeItemAt(const FItemStack& Item, int32 SlotIndex, UObject* Origin) {
    return false;
}

bool UInventoryComponent::TryConsumeItemsInMultipleInventories(const TArray<UInventoryComponent*>& Inventories, const TArray<FItemStack>& ItemsToConsume) {
    return false;
}

int32 UInventoryComponent::TransferStackAtSlotToSlot(int32 FromSlot, UInventoryComponent* TargetInventory, int32 TargetSlot, int32 TargetAmount, bool bAllowSwapping, bool bAllowTransferOverflow) {
    return 0;
}

int32 UInventoryComponent::TransferStack(int32 FromSlot, UInventoryComponent* TargetInventory, bool bAllowTransferOverflow, bool bClampToStackSize) {
    return 0;
}

int32 UInventoryComponent::TransferItemsToInventoryIfConfigIsSame(UInventoryComponent* TargetInventory) {
    return 0;
}

int32 UInventoryComponent::TransferItemsToInventory(UInventoryComponent* TargetInventory) {
    return 0;
}

bool UInventoryComponent::TransferFirstSingleItemToInventory(UInventoryComponent* TargetInventory) {
    return false;
}

void UInventoryComponent::SetItem(int32 Index, FItemStack Item) {
}

int32 UInventoryComponent::RemoveItemConfigAmountAt(UItemConfig* Config, int32 Amount, int32 Slot, UObject* Origin) {
    return 0;
}

int32 UInventoryComponent::RemoveItemConfigAmount(UItemConfig* Config, int32 Amount, UObject* Origin) {
    return 0;
}

int32 UInventoryComponent::RemoveItem(const FItemStack& Stack, UObject* Origin) {
    return 0;
}

void UInventoryComponent::OnUnlockableUnlocked(UUnlockableDataAsset* UnlockableDataAsset) {
}

int32 UInventoryComponent::ModifyAmountFromRules_Remove(UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data) {
    return 0;
}

int32 UInventoryComponent::ModifyAmountFromRules_Add(UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data) {
    return 0;
}

bool UInventoryComponent::IsInventoryFull() {
    return false;
}

bool UInventoryComponent::IsEmpty() const {
    return false;
}

int32 UInventoryComponent::HowManyTimesCanTheRequestedItemsBeConsumedDistributedOverMultipleInventories(const TArray<UInventoryComponent*>& Inventories, const TArray<FItemStack>& RequestedItems) {
    return 0;
}

bool UInventoryComponent::HasAnyItemConfigAsOtherInventory(const UInventoryComponent* OtherInventory) {
    return false;
}

bool UInventoryComponent::HasAllItemConfigsAsOtherInventory(const UInventoryComponent* OtherInventory) {
    return false;
}

FItemStack UInventoryComponent::GetUpToXItemsFromSlot(int32 MaxAmount, int32 SlotIndex) {
    return FItemStack{};
}

FItemStack UInventoryComponent::GetUpToXItemsFromFirstValidConfig(int32 MaxAmount) {
    return FItemStack{};
}

FItemStack UInventoryComponent::GetUpToXItemsFromConfig(int32 MaxAmount, UItemConfig* Type) {
    return FItemStack{};
}

TArray<UItemConfig*> UInventoryComponent::GetUniqueConfigs() const {
    return TArray<UItemConfig*>();
}

TArray<FItemStack> UInventoryComponent::GetTotalItemCount() const {
    return TArray<FItemStack>();
}

int32 UInventoryComponent::GetStackSizeForSlot(int32 SlotIndex, UItemConfig* OverrideItemConfig) {
    return 0;
}

int32 UInventoryComponent::GetSlotIndexOfFirstItem(const FItemStack& Stack) {
    return 0;
}

UInventoryComponent* UInventoryComponent::GetPredictedOrRealInventory() {
    return NULL;
}

int32 UInventoryComponent::GetNumSlots() const {
    return 0;
}

int32 UInventoryComponent::GetNumberOfMinions() {
    return 0;
}

TArray<FItemStack> UInventoryComponent::GetNonEmptyItemStacks() const {
    return TArray<FItemStack>();
}

int32 UInventoryComponent::GetItemCountOfConfig(UItemConfig* Config) const {
    return 0;
}

int32 UInventoryComponent::GetItemCount() const {
    return 0;
}

FItemStack UInventoryComponent::GetItem(int32 Index) {
    return FItemStack{};
}

FItemStack UInventoryComponent::GetFirstItemOfType(int32 Amount, UItemConfig* Type, bool bRemoveItem) {
    return FItemStack{};
}

FItemStack UInventoryComponent::GetFirstItem(int32 Amount, bool bRemoveItem) {
    return FItemStack{};
}

int32 UInventoryComponent::GetFirstEmptySlot() {
    return 0;
}

FFixed UInventoryComponent::GetFillState01() {
    return FFixed{};
}

int32 UInventoryComponent::GetFilledSlotsCount() {
    return 0;
}

int32 UInventoryComponent::GetAmountOfItemsForMultipleInventories(const TArray<UInventoryComponent*>& Inventories, UItemConfig* Item) {
    return 0;
}

TArray<UInventoryComponent*> UInventoryComponent::GetAllUsableInventoriesIncludingSpecificPlayer(ASimulationPlayer* Player) {
    return TArray<UInventoryComponent*>();
}

TArray<FItemStack> UInventoryComponent::GetAllPossibleItems(const TArray<FItemStack>& ItemStacks) {
    return TArray<FItemStack>();
}

TArray<FItemStack> UInventoryComponent::GetAllItemsOfMultipleInventories(const TArray<UInventoryComponent*>& Inventories) {
    return TArray<FItemStack>();
}

void UInventoryComponent::DropSlot(FIntPoint GridPosition, int32 InSlotIndex) {
}

void UInventoryComponent::DropAll(FIntPoint GridPosition) {
}

bool UInventoryComponent::ContainsItemConfigAmount(UItemConfig* Config, int32 Amount) {
    return false;
}

bool UInventoryComponent::ContainsItem(const FItemStack& Stack) {
    return false;
}

void UInventoryComponent::ConsumeAndReturnRest(TArray<FItemStack>& RemainingItems, UObject* Origin) {
}

void UInventoryComponent::Clear() {
}

bool UInventoryComponent::CanTransferItemsTo(UInventoryComponent* TargetInventory, int32 FromSlot, int32 TargetSlot) {
    return false;
}

bool UInventoryComponent::CanRemoveItemAt(UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data) {
    return false;
}

bool UInventoryComponent::CanConsumeItemsDistributedOverMultipleInventories(const TArray<UInventoryComponent*>& Inventories, const TArray<FItemStack>& RequestedItems) {
    return false;
}

bool UInventoryComponent::CanConsumeItems(const TArray<FItemStack>& ItemsToConsume) {
    return false;
}

bool UInventoryComponent::CanAddItems(const TArray<FItemStack>& ItemsToAdd) {
    return false;
}

bool UInventoryComponent::CanAddItemAt(UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data) {
    return false;
}

bool UInventoryComponent::CanAddItem(const FItemStack& ItemsToAdd) {
    return false;
}

void UInventoryComponent::AutoSort() {
}

int32 UInventoryComponent::AddItemToSlot(UItemConfig* Config, int32 Amount, UItemStackData* Data, int32 Slot, UObject* Origin) {
    return 0;
}

int32 UInventoryComponent::AddItems(const TArray<FItemStack>& ItemsToAdd, bool bCommit, UObject* Origin) {
    return 0;
}

int32 UInventoryComponent::AddItemConfigAmountAt(UItemConfig* Config, int32 Amount, int32 Slot, UItemStackData* Data, bool bCommit, UObject* Origin) {
    return 0;
}

int32 UInventoryComponent::AddItemConfigAmount(UItemConfig* Config, int32 Amount, UItemStackData* Data, bool bCommit, UObject* Origin, bool bAllowOverflow) {
    return 0;
}

int32 UInventoryComponent::AddItem(const FItemStack& Stack, UObject* Origin) {
    return 0;
}


