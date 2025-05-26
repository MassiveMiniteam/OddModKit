#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "CarryableSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCarryableSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UCarryableSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

