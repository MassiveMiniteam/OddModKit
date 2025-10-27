#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "WireLessLogicChannel.h"
#include "LogicWirelessReceiverComponent.generated.h"

class UInventoryComponent;
class ULogicOutputSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicWirelessReceiverComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicOutputSimulationComponent> LogicOutput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> Inventory;
    
public:
    ULogicWirelessReceiverComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnSignalInChannelChanged(FWireLessLogicChannel Channel);
    
    UFUNCTION(BlueprintCallable)
    void OnInventoryChanged(int32 SlotIndex);
    
};

