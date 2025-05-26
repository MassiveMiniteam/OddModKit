#include "LogicConnectionMarker.h"

ALogicConnectionMarker::ALogicConnectionMarker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bConnectionState = false;
    this->bSignalState = false;
}

void ALogicConnectionMarker::SetSignalState_Implementation(bool SignalState) {
}


void ALogicConnectionMarker::SetConnectionState_Implementation(bool State) {
}



void ALogicConnectionMarker::OnLogicModeContextStarted() {
}

void ALogicConnectionMarker::OnLogicModeContextEnded() {
}

bool ALogicConnectionMarker::IsConnected() const {
    return false;
}


