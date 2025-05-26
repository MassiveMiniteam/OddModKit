#pragma once
#include "CoreMinimal.h"
#include "SerializedSimulationObject.h"
#include "ItemStackData.generated.h"

class UInventoryComponent;
class UWorld;

UCLASS(Blueprintable)
class UItemStackData : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UItemStackData();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnItemStackDataCreated(UWorld* World);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInventoryComponentUpdate(UInventoryComponent* InventoryComponent, int32 Slot);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetSimulationHashCodeData();
    
public:
    UFUNCTION(BlueprintCallable)
    int32 GetSimulationHashCode();
    
};

