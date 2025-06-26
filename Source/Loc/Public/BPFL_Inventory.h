#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ItemStack.h"
#include "BPFL_Inventory.generated.h"

class ASimulationPlayer;
class UInventoryComponent;
class UItemConfig;
class UObject;

UCLASS(Blueprintable)
class LOC_API UBPFL_Inventory : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBPFL_Inventory();

    UFUNCTION(BlueprintCallable)
    static bool TryConsumeItemsInMultipleInventories(const TArray<UInventoryComponent*>& Inventories, const TArray<FItemStack>& ItemsToConsume);
    
    UFUNCTION(BlueprintCallable)
    static bool TryConsumeItemsForConstruction(ASimulationPlayer* Player, const TArray<FItemStack>& ItemsToConsume);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool PlayerCanAffordConstruction(ASimulationPlayer* Player, const TArray<FItemStack>& ConstructionCost);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool LocalPlayerCanAffordConstruction(const UObject* WorldContext, const TArray<FItemStack>& ConstructionCost);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 HowManyTimesCanTheRequestedItemsBeConsumedDistributedOverMultipleInventories(const TArray<UInventoryComponent*>& Inventories, const TArray<FItemStack>& RequestedItems);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetAmountOfItemsForMultipleInventories(const TArray<UInventoryComponent*>& Inventories, UItemConfig* Item);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UInventoryComponent*> GetAllUsableInventoriesIncludingSpecificPlayer(ASimulationPlayer* Player);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FItemStack> GetAllItemsOfMultipleInventories(const TArray<UInventoryComponent*>& Inventories);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<UInventoryComponent*> GetAllInventoriesUsableToLocalPlayerForConstruction(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool CanConsumeItemsDistributedOverMultipleInventories(const TArray<UInventoryComponent*>& Inventories, const TArray<FItemStack>& RequestedItems);
    
};

