#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "CarryComponent_DelegateDelegate.h"
#include "ItemStack.h"
#include "CarrySimulationComponent.generated.h"

class AGridObject;
class UInventoryComponent;
class UItemConfig;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCarrySimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCarryComponent_Delegate OnAnyInteraction_Delegate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* InventoryComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed PickupDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AGridObject> CarriedGridObject;
    
public:
    UCarrySimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TryPickupGridObjectAt(FIntPoint position);
    
    UFUNCTION(BlueprintCallable)
    bool TryAddToInventory(UInventoryComponent* Inventory);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCarryingItem() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasCarryingCapacity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRemainingCapacity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetPickupDelay() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UItemConfig*> GetItemPickUpWhiteList() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemConfig* GetCarryItemConfig() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FItemStack GetCarriedItemStack() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCarriedItemAmount() const;
    
    UFUNCTION(BlueprintCallable)
    void DropCarriedItem();
    
};

