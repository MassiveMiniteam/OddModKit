#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "GasMovementSimulationComponent.generated.h"

class UInventoryComponent;
class UPositionSimulationComponent;
class UWindSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGasMovementSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWindSimulationComponent> WindComponent;
    
public:
    UGasMovementSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

