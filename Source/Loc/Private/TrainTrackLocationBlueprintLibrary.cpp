#include "TrainTrackLocationBlueprintLibrary.h"

UTrainTrackLocationBlueprintLibrary::UTrainTrackLocationBlueprintLibrary() {
}

bool UTrainTrackLocationBlueprintLibrary::TrainTrackLocation_OrientationIsForwardOnSpline(const FTrainTrackLocation& TrainTrackLocation) {
    return false;
}

double UTrainTrackLocationBlueprintLibrary::TrainTrackLocation_GetPresentationDistanceAlongSpline(const FTrainTrackLocation& TrainTrackLocation) {
    return 0.0;
}


