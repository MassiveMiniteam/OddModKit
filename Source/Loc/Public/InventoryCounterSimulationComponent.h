#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "InventoryCounterEventDelegate.h"
#include "ItemConfigCounter.h"
#include "InventoryCounterSimulationComponent.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UInventoryCounterSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* InventoryComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FItemConfigCounter> ConfigCounters;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FInventoryCounterEvent OnCounterUpdated;
    
    UInventoryCounterSimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnInventorySlotChanged(int32 SlotIndex);
    
public:
    UFUNCTION(BlueprintCallable)
    void IterateSlotIndex(int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCounterForIndex(int32 Index) const;
    
};

