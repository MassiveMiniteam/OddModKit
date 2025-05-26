#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "MinionControllerPaintInventoryHandler.generated.h"

class UControllableMinionSimulationComponent;
class UInventoryComponent;
class UItemConfig;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMinionControllerPaintInventoryHandler : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference PaintInventoryComponentReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* PaintInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UControllableMinionSimulationComponent* ControllableMinionComponent;
    
public:
    UMinionControllerPaintInventoryHandler(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnPaintInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnItemRemoved(UItemConfig* Config, int32 Amount, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    void OnItemAdded(UItemConfig* Config, int32 Amount, UObject* Origin);
    
};

