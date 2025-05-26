#include "PayAndThrowMinionCommand.h"

UPayAndThrowMinionCommand::UPayAndThrowMinionCommand() {
    this->MinionController = NULL;
    this->Minion = NULL;
    this->CursorSelectedActor = NULL;
    this->CursorLockedOnActor = NULL;
    this->bRotateTowardsTarget = false;
    this->bPredictionStarted = false;
}


