#include "SimulationScheduler.h"

ASimulationScheduler::ASimulationScheduler(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AdjustLookAheadLocalTime = 0.00f;
    this->CurrentLookaheadMisses = 0;
    this->NumPlayers = 1;
    this->bIsDesynced = false;
    this->bCheckForDesync = true;
    this->IgnoreDesyncUntilFrame = 0;
    this->SendOutCommandsUntilFrame = 4294967295;
    this->bRecordCommandsToFile = true;
    this->bHasRecordedInitialSaveGame = false;
    this->bIsPlayingBackRecording = false;
}

void ASimulationScheduler::UpdateTimeStepEnabledStateFromGlobalSettings() {
}

void ASimulationScheduler::SetNumPlayers(int32 NewPlayerNum) {
}

void ASimulationScheduler::SetFixedUpdateDisabled(bool bDisabled) {
}

void ASimulationScheduler::LoadPrespawnedSimulationActors() {
}

TArray<FLocPlayerId> ASimulationScheduler::GetSortedPlayerIds() {
    return TArray<FLocPlayerId>();
}

int32 ASimulationScheduler::GetNumPlayers() const {
    return 0;
}

int32 ASimulationScheduler::GetFrameNumberAsInt() const {
    return 0;
}

int32 ASimulationScheduler::GetFrameLookahead() const {
    return 0;
}

FString ASimulationScheduler::DiffHashRecords(FSimulationHashRecord& ServerHash, FSimulationHashRecord& ClientHash, FString& log) {
    return TEXT("");
}

void ASimulationScheduler::ClearSimulation() {
}


