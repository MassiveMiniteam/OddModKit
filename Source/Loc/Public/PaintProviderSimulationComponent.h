#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "ItemStack.h"
#include "PaintProviderSimulationComponent.generated.h"

class UColorItemConfig;
class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPaintProviderSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference PaintInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* PaintInventory;
    
public:
    UPaintProviderSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    FItemStack PullColorItem(bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasColorEquipped();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UColorItemConfig* GetCurrentColorConfig();
    
};

