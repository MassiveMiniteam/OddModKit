#include "LogicRibbonReaderSimulationComponent.h"

ULogicRibbonReaderSimulationComponent::ULogicRibbonReaderSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BitToWrite = 0;
}

void ULogicRibbonReaderSimulationComponent::UpdateRibbonReaderOutput(ULogicConnectionSimulationComponent* Connection) {
}

void ULogicRibbonReaderSimulationComponent::SetBitToWriteTo(const int32 BitIndex) {
}

int32 ULogicRibbonReaderSimulationComponent::GetBitToWriteTo() const {
    return 0;
}


