#pragma once
#include "CoreMinimal.h"
#include "ECapacitySensorCompareRule.h"
#include "ECapacitySensorMode.h"
#include "LogicSensorBaseSimulationComponent.h"
#include "OnSensorCapacityUpdated_DelegateDelegate.h"
#include "SensorCapacitySimulationComponent.generated.h"

class UDynamicInventoryRefSimulation;
class UInventoryComponent;
class UItemConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API USensorCapacitySimulationComponent : public ULogicSensorBaseSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSensorCapacityUpdated_Delegate OnSensorCapacityUpdated_Delegate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 TargetValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ECapacitySensorCompareRule CompareRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ECapacitySensorMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> TargetInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UDynamicInventoryRefSimulation> DynamicTargetInventory;
    
public:
    USensorCapacitySimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTargetValue(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetInventory(UInventoryComponent* Inventory);
    
    UFUNCTION(BlueprintCallable)
    void SetMode(ECapacitySensorMode ModeIn);
    
    UFUNCTION(BlueprintCallable)
    void SetCompareRule(ECapacitySensorCompareRule ModeIn);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnTargetInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnDynamicInventoryChanged(UDynamicInventoryRefSimulation* DynamicInventoryRefSimulation, UInventoryComponent* InventoryComponent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTargetValue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetTargetInventory() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSignalValueOnInvalidInventory() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECapacitySensorMode GetMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECapacitySensorCompareRule GetCompareRule() const;
    
};

