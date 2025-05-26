#include "PlayAnimationCommand.h"

UPlayAnimationCommand::UPlayAnimationCommand() {
    this->SimulationActor = NULL;
    this->Option = EPlayAnimationCommandOptions::Start;
    this->bChooseRandomAnimation = false;
}


