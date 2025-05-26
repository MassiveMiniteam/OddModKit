#include "ResourceRequirementsComponent.h"

UResourceRequirementsComponent::UResourceRequirementsComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DropInventory = NULL;
    this->TargetInventory = NULL;
}

void UResourceRequirementsComponent::OnTargetInventoryRemoved(UItemConfig* Item, int32 Amount, UObject* Origin) {
}

void UResourceRequirementsComponent::OnTargetInventoryItemAdded(UItemConfig* Item, int32 Amount, UObject* Origin) {
}

void UResourceRequirementsComponent::OnDropInventoryItemRemoved(UItemConfig* Item, int32 Amount, UObject* Origin) {
}

void UResourceRequirementsComponent::OnDropInventoryItemAdded(UItemConfig* Item, int32 Amount, UObject* Origin) {
}


