#include "AddToActorToSlotsCommand.h"

UAddToActorToSlotsCommand::UAddToActorToSlotsCommand() {
    this->SlotsComponent = NULL;
    this->Actor = NULL;
    this->SlotIndex = -1;
    this->bAddActor = true;
}


