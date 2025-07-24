#include "LogicOutputSimulationComponent.h"

ULogicOutputSimulationComponent::ULogicOutputSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCopySignalWithCopyTool = false;
}

void ULogicOutputSimulationComponent::SendSignal(FName ChannelID, int32 NewValue) {
}

int32 ULogicOutputSimulationComponent::GetValue(FName ChannelID) const {
    return 0;
}


