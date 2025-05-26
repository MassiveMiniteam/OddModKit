#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TrainTrackLocation.h"
#include "TrainTrackLocationBlueprintLibrary.generated.h"

UCLASS(Blueprintable)
class LOC_API UTrainTrackLocationBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UTrainTrackLocationBlueprintLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool TrainTrackLocation_OrientationIsForwardOnSpline(const FTrainTrackLocation& TrainTrackLocation);
    
    UFUNCTION(BlueprintPure)
    static double TrainTrackLocation_GetPresentationDistanceAlongSpline(const FTrainTrackLocation& TrainTrackLocation);
    
};

