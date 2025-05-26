#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "MarkChunkAsChangedSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMarkChunkAsChangedSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UMarkChunkAsChangedSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

