#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "MarkDeadOnEmptyInventoryComponent.generated.h"

class UInventoryComponent;
class UItemConfig;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMarkDeadOnEmptyInventoryComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> InventoryComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
public:
    UMarkDeadOnEmptyInventoryComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item);
    
};

