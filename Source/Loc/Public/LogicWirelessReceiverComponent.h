#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "LogicWirelessReceiverComponent.generated.h"

class UInventoryComponent;
class UItemConfig;
class ULogicOutputSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicWirelessReceiverComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicOutputSimulationComponent> LogicOutput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemConfig* ItemChannel;
    
public:
    ULogicWirelessReceiverComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateOutput();
    
    UFUNCTION(BlueprintCallable)
    void SetItemChannel(UItemConfig* Item);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnSignalInChannelChanged(UItemConfig* ItemConfig);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnInventoryChanged(int32 SlotIndex);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemConfig* GetItemChannel() const;
    
};

