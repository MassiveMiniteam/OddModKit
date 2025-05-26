#pragma once
#include "CoreMinimal.h"
#include "TrainTracksPoleBaseSimulationComponent.h"
#include "TrainTracksDefaultPoleSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTrainTracksDefaultPoleSimulationComponent : public UTrainTracksPoleBaseSimulationComponent {
    GENERATED_BODY()
public:
    UTrainTracksDefaultPoleSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

