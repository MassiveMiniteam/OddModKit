#include "DesyncDebuggerSubsystem.h"

UDesyncDebuggerSubsystem::UDesyncDebuggerSubsystem() {
    this->bIsSaveGameDumping = false;
    this->SkipDumpFrames = 10;
    this->DumpSkipCounter = 0;
}

void UDesyncDebuggerSubsystem::OnSimulationTick(ASimulationManager* SimulationManager) {
}


