#include "TransferItemStackSimulationCommand.h"

UTransferItemStackSimulationCommand::UTransferItemStackSimulationCommand() {
    this->FromInventory = NULL;
    this->TargetInventory = NULL;
    this->FromSlotIndex = 0;
    this->TargetSlotIndex = 0;
    this->TargetAmount = -1;
    this->bAllowSwap = false;
    this->bAllowTransferOverflow = false;
    this->bDropLeftovers = false;
    this->bIsFirstPredictionCall = true;
}

void UTransferItemStackSimulationCommand::Setup(UInventoryComponent* InFromInventory, int32 FromIndex, UInventoryComponent* InToInventory, int32 ToIndex, int32 InTargetAmount, bool bAllowSwapping, bool bAllowTransferingOverflow) {
}


