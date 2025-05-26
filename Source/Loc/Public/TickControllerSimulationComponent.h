#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "TickControllerSimulationComponent.generated.h"

class ASimulationActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTickControllerSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UTickControllerSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnTickingComponentsChanged(ASimulationActor* SimActor);
    
};

