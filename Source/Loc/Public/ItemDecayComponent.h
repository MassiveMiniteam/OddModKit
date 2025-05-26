#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Fixed.h"
#include "ItemDecayInventoryEventDelegate.h"
#include "OnItemDecayed_DelegateDelegate.h"
#include "SimulationTimerComponent.h"
#include "ItemDecayComponent.generated.h"

class UInventoryComponent;
class UItemConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UItemDecayComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemDecayed_Delegate OnItemDecayed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemDecayInventoryEvent OnDecayInventoryChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference DecayInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed Interval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AmountPerLoop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Slot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRemoveItemOnTimerStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> InventoryComponent;
    
public:
    UItemDecayComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetInterval(FFixed IntervalIn);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnInventoryChanged(UInventoryComponent* Inventory, bool bBAdded, UItemConfig* Item);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetTargetInventoryComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetRemoveItemOnTimerStart() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetInterval() const;
    
};

