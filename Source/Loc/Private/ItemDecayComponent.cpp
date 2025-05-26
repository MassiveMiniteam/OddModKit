#include "ItemDecayComponent.h"

UItemDecayComponent::UItemDecayComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AmountPerLoop = 1;
    this->Slot = -1;
    this->bRemoveItemOnTimerStart = false;
}

void UItemDecayComponent::SetInterval(FFixed IntervalIn) {
}

void UItemDecayComponent::OnInventoryChanged(UInventoryComponent* Inventory, bool bBAdded, UItemConfig* Item) {
}

UInventoryComponent* UItemDecayComponent::GetTargetInventoryComponent() const {
    return NULL;
}

bool UItemDecayComponent::GetRemoveItemOnTimerStart() const {
    return false;
}

FFixed UItemDecayComponent::GetInterval() const {
    return FFixed{};
}


