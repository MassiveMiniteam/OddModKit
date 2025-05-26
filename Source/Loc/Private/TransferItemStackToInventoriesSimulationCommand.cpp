#include "TransferItemStackToInventoriesSimulationCommand.h"

UTransferItemStackToInventoriesSimulationCommand::UTransferItemStackToInventoriesSimulationCommand() {
    this->FromInventory = NULL;
    this->FromSlotIndex = 0;
    this->bPrioritizeMinions = false;
    this->bIsFirstPredictionCall = true;
}

void UTransferItemStackToInventoriesSimulationCommand::Setup(UInventoryComponent* InFromInventory, int32 FromIndex, TArray<UInventoryComponent*> InToInventories, bool bInPrioritizeMinions) {
}


