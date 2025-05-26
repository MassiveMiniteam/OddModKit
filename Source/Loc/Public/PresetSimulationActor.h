#pragma once
#include "CoreMinimal.h"
#include "SimulationActor.h"
#include "PresetSimulationActor.generated.h"

UCLASS(Blueprintable)
class LOC_API APresetSimulationActor : public ASimulationActor {
    GENERATED_BODY()
public:
    APresetSimulationActor(const FObjectInitializer& ObjectInitializer);

};

