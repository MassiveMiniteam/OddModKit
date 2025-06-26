#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "ItemStack.h"
#include "ProductionRateBoundTimerComponent.h"
#include "ItemTaggerSimulationComponent.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UItemTaggerSimulationComponent : public UProductionRateBoundTimerComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InputSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TagSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InputInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference OutputInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* InputInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* OutputInventory;
    
public:
    UItemTaggerSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FItemStack GetTagItemStack() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FItemStack GetBaseItemStack() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanCombineItems();
    
};

