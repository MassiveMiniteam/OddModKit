#pragma once
#include "CoreMinimal.h"
#include "SimulationActorPreset.h"
#include "MinionSimulationActorPreset.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMinionSimulationActorPreset : public USimulationActorPreset {
    GENERATED_BODY()
public:
    UMinionSimulationActorPreset(const FObjectInitializer& ObjectInitializer);

};

