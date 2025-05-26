#include "TrainTrackConnectionMarker.h"

ATrainTrackConnectionMarker::ATrainTrackConnectionMarker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MyConnectionComponent = NULL;
}

void ATrainTrackConnectionMarker::OnContextUpdated() {
}

void ATrainTrackConnectionMarker::OnContextConnectionStateUpdated(FTrainsConnectionChangeDelegateParams DelegateParams) {
}



