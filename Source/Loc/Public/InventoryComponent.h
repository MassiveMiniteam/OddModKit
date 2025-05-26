#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "InventoryChangeEventDelegate.h"
#include "InventoryEventDelegate.h"
#include "InventorySlotDeletedEventDelegate.h"
#include "ItemAddedEventDelegate.h"
#include "ItemStack.h"
#include "SlotChangedEventDelegate.h"
#include "InventoryComponent.generated.h"

class ASimulationPlayer;
class UInventoryComponent;
class UInventoryRule;
class UItemConfig;
class UItemStackData;
class UObject;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UInventoryComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverflowAllowed;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> DefaultItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UUnlockableDataAsset*, int32> UnlockableSlotUpgrades;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDeleteInsteadOfSwap;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultNumSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> Items;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInventoryRule*> Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddDefaultRules;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FInventoryEvent OnInventorySizeUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FInventoryEvent OnBigSlotUnlocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FItemAddedEvent OnItemAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FItemAddedEvent OnItemRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventorySlotDeletedEvent OnItemSlotDeleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSlotChangedEvent OnSlotChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FInventoryEvent OnAddHasOverflow;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FInventoryChangeEvent OnInventoryChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInFirstPredictionTransfer;
    
    UInventoryComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool TryToConsumeItems(const TArray<FItemStack>& ItemsToConsume, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    bool TryToConsumeItemAt(const FItemStack& Item, int32 SlotIndex, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    static bool TryConsumeItemsInMultipleInventories(const TArray<UInventoryComponent*>& Inventories, const TArray<FItemStack>& ItemsToConsume);
    
    UFUNCTION(BlueprintCallable)
    int32 TransferStackAtSlotToSlot(int32 FromSlot, UInventoryComponent* TargetInventory, int32 TargetSlot, int32 TargetAmount, bool bAllowSwapping, bool bAllowTransferOverflow);
    
    UFUNCTION(BlueprintCallable)
    int32 TransferStack(int32 FromSlot, UInventoryComponent* TargetInventory, bool bAllowTransferOverflow, bool bClampToStackSize);
    
    UFUNCTION(BlueprintCallable)
    int32 TransferItemsToInventoryIfConfigIsSame(UInventoryComponent* TargetInventory);
    
    UFUNCTION(BlueprintCallable)
    int32 TransferItemsToInventory(UInventoryComponent* TargetInventory);
    
    UFUNCTION(BlueprintCallable)
    bool TransferFirstSingleItemToInventory(UInventoryComponent* TargetInventory);
    
    UFUNCTION(BlueprintCallable)
    void SetItem(int32 Index, FItemStack Item);
    
    UFUNCTION(BlueprintCallable)
    int32 RemoveItemConfigAmountAt(UItemConfig* Config, int32 Amount, int32 Slot, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    int32 RemoveItemConfigAmount(UItemConfig* Config, int32 Amount, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    int32 RemoveItem(const FItemStack& Stack, UObject* Origin);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnUnlockableUnlocked(UUnlockableDataAsset* UnlockableDataAsset);
    
protected:
    UFUNCTION(BlueprintCallable)
    int32 ModifyAmountFromRules_Remove(UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data);
    
    UFUNCTION(BlueprintCallable)
    int32 ModifyAmountFromRules_Add(UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInventoryFull();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEmpty() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 HowManyTimesCanTheRequestedItemsBeConsumedDistributedOverMultipleInventories(const TArray<UInventoryComponent*>& Inventories, const TArray<FItemStack>& RequestedItems);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnyItemConfigAsOtherInventory(const UInventoryComponent* OtherInventory);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAllItemConfigsAsOtherInventory(const UInventoryComponent* OtherInventory);
    
    UFUNCTION(BlueprintCallable)
    FItemStack GetUpToXItemsFromSlot(int32 MaxAmount, int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    FItemStack GetUpToXItemsFromFirstValidConfig(int32 MaxAmount);
    
    UFUNCTION(BlueprintCallable)
    FItemStack GetUpToXItemsFromConfig(int32 MaxAmount, UItemConfig* Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UItemConfig*> GetUniqueConfigs() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FItemStack> GetTotalItemCount() const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetStackSizeForSlot(int32 SlotIndex, UItemConfig* OverrideItemConfig);
    
    UFUNCTION(BlueprintCallable)
    int32 GetSlotIndexOfFirstItem(const FItemStack& Stack);
    
    UFUNCTION(BlueprintCallable)
    UInventoryComponent* GetPredictedOrRealInventory();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumSlots() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumberOfMinions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<FItemStack> GetNonEmptyItemStacks() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetItemCountOfConfig(UItemConfig* Config) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetItemCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FItemStack GetItem(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    FItemStack GetFirstItemOfType(int32 Amount, UItemConfig* Type, bool bRemoveItem);
    
    UFUNCTION(BlueprintCallable)
    FItemStack GetFirstItem(int32 Amount, bool bRemoveItem);
    
    UFUNCTION(BlueprintCallable)
    int32 GetFirstEmptySlot();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetFillState01();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFilledSlotsCount();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetAmountOfItemsForMultipleInventories(const TArray<UInventoryComponent*>& Inventories, UItemConfig* Item);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UInventoryComponent*> GetAllUsableInventoriesIncludingSpecificPlayer(ASimulationPlayer* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FItemStack> GetAllPossibleItems(const TArray<FItemStack>& ItemStacks);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FItemStack> GetAllItemsOfMultipleInventories(const TArray<UInventoryComponent*>& Inventories);
    
    UFUNCTION(BlueprintCallable)
    void DropSlot(FIntPoint GridPosition, int32 InSlotIndex);
    
    UFUNCTION(BlueprintCallable)
    void DropAll(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable)
    bool ContainsItemConfigAmount(UItemConfig* Config, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    bool ContainsItem(const FItemStack& Stack);
    
    UFUNCTION(BlueprintCallable)
    void ConsumeAndReturnRest(TArray<FItemStack>& RemainingItems, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    void Clear();
    
    UFUNCTION(BlueprintCallable)
    bool CanTransferItemsTo(UInventoryComponent* TargetInventory, int32 FromSlot, int32 TargetSlot);
    
protected:
    UFUNCTION(BlueprintCallable)
    bool CanRemoveItemAt(UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool CanConsumeItemsDistributedOverMultipleInventories(const TArray<UInventoryComponent*>& Inventories, const TArray<FItemStack>& RequestedItems);
    
    UFUNCTION(BlueprintCallable)
    bool CanConsumeItems(const TArray<FItemStack>& ItemsToConsume);
    
    UFUNCTION(BlueprintCallable)
    bool CanAddItems(const TArray<FItemStack>& ItemsToAdd);
    
protected:
    UFUNCTION(BlueprintCallable)
    bool CanAddItemAt(UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data);
    
public:
    UFUNCTION(BlueprintCallable)
    bool CanAddItem(const FItemStack& ItemsToAdd);
    
    UFUNCTION(BlueprintCallable)
    void AutoSort();
    
    UFUNCTION(BlueprintCallable)
    int32 AddItemToSlot(UItemConfig* Config, int32 Amount, UItemStackData* Data, int32 Slot, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    int32 AddItems(const TArray<FItemStack>& ItemsToAdd, bool bCommit, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    int32 AddItemConfigAmountAt(UItemConfig* Config, int32 Amount, int32 Slot, UItemStackData* Data, bool bCommit, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    int32 AddItemConfigAmount(UItemConfig* Config, int32 Amount, UItemStackData* Data, bool bCommit, UObject* Origin, bool bAllowOverflow);
    
    UFUNCTION(BlueprintCallable)
    int32 AddItem(const FItemStack& Stack, UObject* Origin);
    
};

