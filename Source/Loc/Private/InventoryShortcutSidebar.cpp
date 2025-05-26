#include "InventoryShortcutSidebar.h"

UInventoryShortcutSidebar::UInventoryShortcutSidebar() {
    this->MyReferencedActor = NULL;
    this->Btn_Sort = NULL;
    this->Btn_Trash = NULL;
    this->Btn_TransferAll = NULL;
    this->Btn_PullSame = NULL;
}

void UInventoryShortcutSidebar::Setup(ASimulationActor* ReferencedSimulationActor, FInventoryShortcutsInventories InInventoryReferences) {
}


