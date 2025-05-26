#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "InventoryAutoFillComponent.generated.h"

class UInventoryComponent;
class UItemConfig;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UInventoryAutoFillComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference FromInventoryReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference ToInventoryReference;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> FromInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> ToInventory;
    
public:
    UInventoryAutoFillComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnToInventoryItemRemoved(UItemConfig* Item, int32 Amount, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    void OnFromInventoryItemAdded(UItemConfig* Item, int32 Amount, UObject* Origin);
    
    UFUNCTION(BlueprintCallable)
    void FillInventory();
    
};

