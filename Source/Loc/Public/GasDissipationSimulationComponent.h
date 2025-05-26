#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "SimulationTimerComponent.h"
#include "GasDissipationSimulationComponent.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGasDissipationSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Interval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInventoryComponent> InventoryComponent;
    
public:
    UGasDissipationSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

