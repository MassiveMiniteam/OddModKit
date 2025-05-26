#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "ResourcesCounterSimulationComponent.generated.h"

class UInventoryComponent;
class UItemConfig;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UResourcesCounterSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* MyInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<UItemConfig*, int32> ItemsToAmount;
    
public:
    UResourcesCounterSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnItemAdded(UItemConfig* Config, int32 Amount, UObject* Origin);
    
};

