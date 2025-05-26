#include "RelocateGridObjectSimulationCommand.h"

URelocateGridObjectSimulationCommand::URelocateGridObjectSimulationCommand() {
    this->Rotation = 0;
    this->GridObject = NULL;
    this->PreviousPlacedGridObject = NULL;
    this->ExecutingPlayer = NULL;
    this->CachedSimulationManager = NULL;
    this->CachedDefaultObject = NULL;
    this->CachedPresentationActor = NULL;
    this->PredictedPresentationActor = NULL;
}


