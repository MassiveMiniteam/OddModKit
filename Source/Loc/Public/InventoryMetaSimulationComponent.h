#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "InventoryMetaEventDelegate.h"
#include "InventorySlotMeta.h"
#include "InventoryMetaSimulationComponent.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UInventoryMetaSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryMetaEvent OnMetadataChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference TargetInventoryRef;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FInventorySlotMeta> MetaData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInventoryComponent* TargetInventory;
    
public:
    UInventoryMetaSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnInventorySlotChanged(int32 SlotIndex);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRefillFromInventoryPossible(UInventoryComponent* ProviderInventory);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetTargetInventory() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FInventorySlotMeta GetMetaForSlot(int32 Slot);
    
    UFUNCTION(BlueprintCallable)
    void ClearMetaForSlot(int32 Slot);
    
};

