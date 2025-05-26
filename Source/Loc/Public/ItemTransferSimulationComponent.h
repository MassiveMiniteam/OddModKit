#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Fixed.h"
#include "ItemStack.h"
#include "ItemTransferComponentDelegateDelegate.h"
#include "ItemTransferData.h"
#include "SimulationTimerComponent.h"
#include "ItemTransferSimulationComponent.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UItemTransferSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemTransferComponentDelegate OnItemTransportStarted;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference TargetInventoryReference;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed TimeBetweenItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed ItemTransferDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SourceInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> SourceInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> TargetInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FItemTransferData> CurrentlyTransportedItems;
    
public:
    UItemTransferSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTargetInventory(UInventoryComponent* Inventory);
    
    UFUNCTION(BlueprintCallable)
    void SetItemTransferDuration(FFixed NewDuration);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetItemTransferDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetItemStartInterval() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FItemStack> GetAllCurrentlyTransportedItems();
    
};

