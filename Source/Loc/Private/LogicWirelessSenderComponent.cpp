#include "LogicWirelessSenderComponent.h"

ULogicWirelessSenderComponent::ULogicWirelessSenderComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ItemChannel = NULL;
}

void ULogicWirelessSenderComponent::SetItemChannel(UItemConfig* Item) {
}

void ULogicWirelessSenderComponent::OnSignalChanged(ULogicConnectionSimulationComponent* Input) {
}

void ULogicWirelessSenderComponent::OnInventoryChanged(int32 SlotIndex) {
}

ULogicInputSimulationComponent* ULogicWirelessSenderComponent::GetLogicInput() const {
    return NULL;
}

UItemConfig* ULogicWirelessSenderComponent::GetItemChannel() const {
    return NULL;
}


