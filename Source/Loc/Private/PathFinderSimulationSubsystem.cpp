#include "PathFinderSimulationSubsystem.h"

UPathFinderSimulationSubsystem::UPathFinderSimulationSubsystem() {
    this->ClosedSetLimit = 500;
    this->ForceCompleteClosedSetLimit = 2000;
}

UPathFindingRequest* UPathFinderSimulationSubsystem::FindPath(const FPathFindingSettings& Settings, FIntVector FromPosition, FIntVector ToPosition) {
    return NULL;
}


