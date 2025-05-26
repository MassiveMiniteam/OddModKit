#include "LogicRibbonWriterSimulationComponent.h"

ULogicRibbonWriterSimulationComponent::ULogicRibbonWriterSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BitToWrite = 0;
}

void ULogicRibbonWriterSimulationComponent::UpdateRibbonWriterOutput(ULogicConnectionSimulationComponent* Connection) {
}

void ULogicRibbonWriterSimulationComponent::SetBitToWriteTo(const int32 BitIndex) {
}

int32 ULogicRibbonWriterSimulationComponent::GetBitToWriteTo() const {
    return 0;
}


