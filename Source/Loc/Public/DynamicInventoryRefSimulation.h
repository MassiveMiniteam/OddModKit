#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "DynamicInventoryEventDelegate.h"
#include "DynamicInventoryRefSimulation.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UDynamicInventoryRefSimulation : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDynamicInventoryEvent OnDynamicInventoryChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* TargetInventory;
    
public:
    UDynamicInventoryRefSimulation(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTargetInventory(UInventoryComponent* InventoryIn);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetTargetInventory() const;
    
};

