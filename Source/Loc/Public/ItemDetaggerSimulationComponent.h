#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "BaseItemTagItemPair.h"
#include "ItemStack.h"
#include "ProductionRateBoundTimerComponent.h"
#include "ItemDetaggerSimulationComponent.generated.h"

class UInventoryComponent;
class UItemConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UItemDetaggerSimulationComponent : public UProductionRateBoundTimerComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InputInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference OutputInventoryBaseItemReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference OutputInventoryTagItemReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* InputInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* OutputInventory_BaseItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* OutputInventory_TagItem;
    
public:
    UItemDetaggerSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemConfig* GetItemConfigForTag() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FItemStack GetBaseItemStack() const;
    
    UFUNCTION(BlueprintCallable)
    bool CanUseDetagger();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAddItemsToTargetInventories();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBaseItemTagItemPair CalculateOutput();
    
};

