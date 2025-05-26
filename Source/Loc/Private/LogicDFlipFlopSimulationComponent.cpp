#include "LogicDFlipFlopSimulationComponent.h"

ULogicDFlipFlopSimulationComponent::ULogicDFlipFlopSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OldClockValue = -1;
}

void ULogicDFlipFlopSimulationComponent::RefreshOutput(ULogicConnectionSimulationComponent* LogicConnection) {
}


