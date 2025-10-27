#include "LogicWirelessSenderComponent.h"

ULogicWirelessSenderComponent::ULogicWirelessSenderComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void ULogicWirelessSenderComponent::OnSignalChanged(ULogicConnectionSimulationComponent* Input) {
}

void ULogicWirelessSenderComponent::OnInventoryChanged(int32 SlotIndex) {
}

ULogicInputSimulationComponent* ULogicWirelessSenderComponent::GetLogicInput() const {
    return NULL;
}


