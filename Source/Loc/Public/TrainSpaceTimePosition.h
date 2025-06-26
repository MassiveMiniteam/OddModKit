#pragma once
#include "CoreMinimal.h"
#include "TrainTrackLocation.h"
#include "TrainSpaceTimePosition.generated.h"

USTRUCT(BlueprintType)
struct FTrainSpaceTimePosition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTrainTrackLocation Location;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double Time;
    
    LOC_API FTrainSpaceTimePosition();
};

