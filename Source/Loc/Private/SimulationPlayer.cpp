#include "SimulationPlayer.h"
#include "InventoryComponent.h"

ASimulationPlayer::ASimulationPlayer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
    this->MinionInventoryReference = NULL;
    this->HotbarLength = 10;
    this->CursorInventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("CursorInventory"));
    this->CursorCancelInventory = NULL;
    this->CursorCancelSlotIndex = 0;
    this->bPlayerIsOnline = false;
}

void ASimulationPlayer::TryToAssignCharacterPresentation() {
}

void ASimulationPlayer::ReviveSimulationPlayer() {
}

void ASimulationPlayer::OnPickedUpItem(UItemConfig* Config, int32 Amount, UObject* Origin) {
}

void ASimulationPlayer::OnCursorItemAdded(UItemConfig* Config, int32 Amount, UObject* Origin) {
}


bool ASimulationPlayer::IsPlayerOnline() const {
    return false;
}


