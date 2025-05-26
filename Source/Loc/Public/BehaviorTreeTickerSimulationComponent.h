#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "BehaviorTreeTickerSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UBehaviorTreeTickerSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UBehaviorTreeTickerSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

