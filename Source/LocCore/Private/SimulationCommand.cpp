#include "SimulationCommand.h"

USimulationCommand::USimulationCommand() {
}

FString USimulationCommand::ToString_Implementation() {
    return TEXT("");
}

void USimulationCommand::Schedule(const UObject* WorldContext, bool bScheduleAsPrediction) {
}

void USimulationCommand::OnRunCommand_Implementation(ASimulationManager* SimulationManager, bool bRunAsPrediction) {
}

bool USimulationCommand::GetSupportsPrediction_Implementation() {
    return false;
}

bool USimulationCommand::GetSupportsLoadingFromSavegame_Implementation() {
    return false;
}


