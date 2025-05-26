#include "MinionControllerPaintInventoryHandler.h"

UMinionControllerPaintInventoryHandler::UMinionControllerPaintInventoryHandler(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PaintInventory = NULL;
    this->ControllableMinionComponent = NULL;
}

void UMinionControllerPaintInventoryHandler::OnPaintInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item) {
}

void UMinionControllerPaintInventoryHandler::OnItemRemoved(UItemConfig* Config, int32 Amount, UObject* Origin) {
}

void UMinionControllerPaintInventoryHandler::OnItemAdded(UItemConfig* Config, int32 Amount, UObject* Origin) {
}


