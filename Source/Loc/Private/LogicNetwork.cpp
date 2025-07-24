#include "LogicNetwork.h"

ALogicNetwork::ALogicNetwork(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurrentSignalValue = 0;
}

void ALogicNetwork::RemoveConnection(ULogicConnectionSimulationComponent* Connection) {
}

void ALogicNetwork::NotifySignalChange() {
}

bool ALogicNetwork::HasConnection(ULogicConnectionSimulationComponent* Connection) const {
    return false;
}

FName ALogicNetwork::GetLogicChannel() {
    return NAME_None;
}

int32 ALogicNetwork::GetAsIntFromChannel(FName Channel) const {
    return 0;
}

int32 ALogicNetwork::GetAsInt() const {
    return 0;
}

bool ALogicNetwork::GetAsBoolFromChannel(FName Channel) const {
    return false;
}

bool ALogicNetwork::GetAsBool() const {
    return false;
}

TArray<int32> ALogicNetwork::GetActiveBitsOnRibbonChannel() const {
    return TArray<int32>();
}

void ALogicNetwork::AddConnection(ULogicConnectionSimulationComponent* Connection) {
}


