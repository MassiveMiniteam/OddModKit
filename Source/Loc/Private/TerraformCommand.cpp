#include "TerraformCommand.h"

UTerraformCommand::UTerraformCommand() {
    this->PayCostInventory = NULL;
    this->bDigUp = false;
}

bool UTerraformCommand::CanTerraformPosition(const UObject* WorldContext, FTerraformPosition Target) {
    return false;
}


