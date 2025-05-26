#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "ItemStack.h"
#include "SupplyComponentBoolEventDelegate.h"
#include "SupplySimulationComponent.generated.h"

class UAIPerceptionSimulationComponent;
class UInventoryComponent;
class UItemConfig;
class UObject;
class USimulationTimerComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API USupplySimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSupplyComponentBoolEvent OnCanAffordStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed SupplyInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SupplyInventoryComponentReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIPerceptionSimulationComponent* PerceptionSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimulationTimerComponent* SimulationTimerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* SupplyInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStack SupplyItemStack;
    
public:
    USupplySimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnTimerFired(USimulationTimerComponent* InSimulationTimerComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSupplySuccessEvent();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSupplyFailEvent();
    
    UFUNCTION(BlueprintCallable)
    void OnItemRemovedFromSupplyInventory(UItemConfig* Config, int32 Amount, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    void OnItemAddedToSupplyInventory(UItemConfig* Config, int32 Amount, UObject* Origin);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void CanAffordStateChangedEvent(bool bState);
    
};

