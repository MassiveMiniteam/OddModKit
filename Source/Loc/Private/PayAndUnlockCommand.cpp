#include "PayAndUnlockCommand.h"

UPayAndUnlockCommand::UPayAndUnlockCommand() {
    this->InventoryComponent = NULL;
    this->DataAsset = NULL;
    this->SourceActor = NULL;
    this->bCostsCanBePaidFromSupplyChests = true;
}


