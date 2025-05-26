#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "LogicWirelessSenderComponent.generated.h"

class UInventoryComponent;
class UItemConfig;
class ULogicConnectionSimulationComponent;
class ULogicInputSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicWirelessSenderComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicInputSimulationComponent> LogicInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemConfig* ItemChannel;
    
public:
    ULogicWirelessSenderComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void SetItemChannel(UItemConfig* Item);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnSignalChanged(ULogicConnectionSimulationComponent* Input);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnInventoryChanged(int32 SlotIndex);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ULogicInputSimulationComponent* GetLogicInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemConfig* GetItemChannel() const;
    
};

