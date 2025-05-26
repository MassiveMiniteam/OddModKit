#include "LogicOutputSimulationComponent.h"

ULogicOutputSimulationComponent::ULogicOutputSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCopySignalWithCopyTool = false;
    this->MaxPropagationTicks = 0;
    this->PropagationTicksCounter = 0;
}

void ULogicOutputSimulationComponent::SendSignal(FName ChannelID, int32 NewValue) {
}

void ULogicOutputSimulationComponent::PropagationTick() {
}

bool ULogicOutputSimulationComponent::IsIndeterminate() const {
    return false;
}

int32 ULogicOutputSimulationComponent::GetValue(FName ChannelID) const {
    return 0;
}


