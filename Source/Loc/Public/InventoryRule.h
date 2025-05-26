#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InventoryRule.generated.h"

class UInventoryComponent;
class UItemConfig;
class UItemStackData;
class UObject;
class UUnlockableDataAsset;

UCLASS(Blueprintable)
class LOC_API UInventoryRule : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* Precondition;
    
    UInventoryRule();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 OverrideStackSize(UInventoryComponent* Inventory, UItemConfig* Config, int32 DefaultStackSize, int32 Index, UItemStackData* Data);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 ModifyAmount_Remove(UInventoryComponent* Inventory, UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 ModifyAmount_Add(UInventoryComponent* Inventory, UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool IsActive(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanRemoveItemAt(UInventoryComponent* Inventory, UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanAddItemAt(UInventoryComponent* Inventory, UItemConfig* Config, int32 Amount, int32 Index, UItemStackData* Data);
    
};

