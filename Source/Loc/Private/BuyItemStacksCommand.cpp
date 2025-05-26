#include "BuyItemStacksCommand.h"

UBuyItemStacksCommand::UBuyItemStacksCommand() {
    this->PayCostInventory = NULL;
    this->BoughtItemTargetInventory = NULL;
    this->bCostsCanBePaidFromSupplyChests = true;
}


