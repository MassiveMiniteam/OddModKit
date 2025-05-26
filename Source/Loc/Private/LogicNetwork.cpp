#include "LogicNetwork.h"

ALogicNetwork::ALogicNetwork(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurrentSignalValue = 0;
    this->CurrentSignalValueRibbon = 0;
    this->LogicChannel = TEXT("DefaultChannel");
}

void ALogicNetwork::RemoveConnection(ULogicConnectionSimulationComponent* Connection) {
}

void ALogicNetwork::NotifySignalChange() {
}

bool ALogicNetwork::HasConnection(ULogicConnectionSimulationComponent* Connection) {
    return false;
}

FName ALogicNetwork::GetLogicChannel() {
    return NAME_None;
}

int32 ALogicNetwork::GetAsIntFromChannel(FName Channel) {
    return 0;
}

int32 ALogicNetwork::GetAsInt() {
    return 0;
}

bool ALogicNetwork::GetAsBoolFromChannel(FName Channel) {
    return false;
}

bool ALogicNetwork::GetAsBool() {
    return false;
}

TArray<int32> ALogicNetwork::GetActiveBitsOnRibbonChannel() {
    return TArray<int32>();
}

void ALogicNetwork::AddConnection(ULogicConnectionSimulationComponent* Connection) {
}


