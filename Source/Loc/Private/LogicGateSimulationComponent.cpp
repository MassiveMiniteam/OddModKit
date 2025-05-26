#include "LogicGateSimulationComponent.h"

ULogicGateSimulationComponent::ULogicGateSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Output = NULL;
    this->Mode = BooleanOperation::AND;
}

void ULogicGateSimulationComponent::RefreshOutput(ULogicConnectionSimulationComponent* LogicConnection) {
}


