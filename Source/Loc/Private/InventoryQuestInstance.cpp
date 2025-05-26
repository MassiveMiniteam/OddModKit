#include "InventoryQuestInstance.h"
#include "InventoryComponent.h"

AInventoryQuestInstance::AInventoryQuestInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->QuestInstanceInventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("QuestInstanceInventory"));
}

void AInventoryQuestInstance::OnInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item) {
}


