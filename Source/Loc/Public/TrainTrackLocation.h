#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "TrainTrackLocation.generated.h"

class UTrainTrackSegmentSimulationComponent;
class UTrainTracksPoleBaseSimulationComponent;

USTRUCT(BlueprintType)
struct LOC_API FTrainTrackLocation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTrainTrackSegmentSimulationComponent> Segment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTrainTracksPoleBaseSimulationComponent> TargetPole;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed64 LocalDistanceAlongSegment;
    
    FTrainTrackLocation();
};

