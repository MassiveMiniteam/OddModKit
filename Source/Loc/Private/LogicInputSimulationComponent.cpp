#include "LogicInputSimulationComponent.h"

ULogicInputSimulationComponent::ULogicInputSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

int32 ULogicInputSimulationComponent::GetAsInt(FName Channel) const {
    return 0;
}

bool ULogicInputSimulationComponent::GetAsBool(FName Channel) const {
    return false;
}


