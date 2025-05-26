#pragma once
#include "CoreMinimal.h"
#include "ComponentRegistrationSubsystem.h"
#include "ItemStack.h"
#include "GlobalConstructionInventorySubsystem.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable)
class LOC_API UGlobalConstructionInventorySubsystem : public UComponentRegistrationSubsystem {
    GENERATED_BODY()
public:
    UGlobalConstructionInventorySubsystem();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FItemStack> GetAllItems() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UInventoryComponent*> GetAllInventoriesIncludingSpecificPlayer(UInventoryComponent* PlayerInventory) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UInventoryComponent*> GetAllInventoriesIncludingLocalPlayer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UInventoryComponent*> GetAllInventories() const;
    
};

