#include "LogicWirelessReceiverComponent.h"

ULogicWirelessReceiverComponent::ULogicWirelessReceiverComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ItemChannel = NULL;
}

void ULogicWirelessReceiverComponent::UpdateOutput() {
}

void ULogicWirelessReceiverComponent::SetItemChannel(UItemConfig* Item) {
}

void ULogicWirelessReceiverComponent::OnSignalInChannelChanged(UItemConfig* ItemConfig) {
}

void ULogicWirelessReceiverComponent::OnInventoryChanged(int32 SlotIndex) {
}

UItemConfig* ULogicWirelessReceiverComponent::GetItemChannel() const {
    return NULL;
}


