#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "ConnectionData.h"
#include "InventoryConnectorSimulationComponent.generated.h"

class UDynamicInventoryRefSimulation;
class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UInventoryConnectorSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InventoryReference;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConnectionData> ConnectionData;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UDynamicInventoryRefSimulation> DynamicInventory;
    
public:
    UInventoryConnectorSimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnDynamicInventoryTargetChanged(UDynamicInventoryRefSimulation* Component, UInventoryComponent* NewInventory);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetInventory() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetInteractionTiles(bool Inputs) const;
    
};

