#include "GasBlockerComponent.h"

UGasBlockerComponent::UGasBlockerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GasEmitter = NULL;
    this->Inventory = NULL;
    this->Slot = 0;
    this->ItemToAdd = NULL;
    this->bIsBlockingGas = false;
}

void UGasBlockerComponent::OnInventoryChanged(UInventoryComponent* InInventory, bool bAdded, UItemConfig* Item) {
}

void UGasBlockerComponent::OnGridPositionUnderneathChanged(AGridObject* GridObject, FIntPoint GridPosition) {
}

void UGasBlockerComponent::OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem) {
}

bool UGasBlockerComponent::IsBlockingPossible() {
    return false;
}


