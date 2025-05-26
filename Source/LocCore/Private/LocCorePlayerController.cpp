#include "LocCorePlayerController.h"

ALocCorePlayerController::ALocCorePlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ClickEventKeys.AddDefaulted(1);
    this->bIsStreamingToClient = false;
    this->bIsStreamingSaveGame = false;
    this->SaveGameTotalFragmentCount = 0;
    this->SaveGameCurrentFragmentCount = 0;
    this->BytesPerFragment = 1000;
    this->LastPingTime = 0;
    this->CurrentPingDelay = 0;
    this->Ping = 0;
    this->bSyncCommands = true;
    this->TargetNumPlayers = 0;
    this->DesyncServerHashFrameNumber = 0;
    this->DesyncTargetHashFrameNumber = 0;
    this->DesyncSendOutServerHashFrameNumber = 0;
    this->SyncIndexCounter = 0;
    this->bHasGameStarted = false;
}

void ALocCorePlayerController::StreamSavegameOnGameStarted(int32 NumPlayers, const TArray<uint8>& SerializedGameData) {
}

void ALocCorePlayerController::StreamDesyncReportToClient(FSimulationHashRecord& Record, int32 Frame) {
}

void ALocCorePlayerController::StartNetworkGame() {
}

void ALocCorePlayerController::ServerSetPlayerIsReadyToSimulate_Implementation() {
}

void ALocCorePlayerController::ServerSetPlayerIsReady_Implementation() {
}

void ALocCorePlayerController::ServerRequestSerializedSimulation_Implementation(int32 Frame) {
}

void ALocCorePlayerController::ServerPing_Implementation(double PingTime) {
}

void ALocCorePlayerController::ServerNotifyFinishedReceivingSavegame_Implementation() {
}

void ALocCorePlayerController::ServerDistributeCommands_Implementation(int32 PlayerNum, const TArray<uint8>& SyncRecords) {
}

void ALocCorePlayerController::ServerAnswerPlayerUniqueId_Implementation(FLocPlayerId NetId) {
}

void ALocCorePlayerController::ServerAckCommands_Implementation(bool bIsAckAck, const TArray<uint32>& SyncRecords) {
}

void ALocCorePlayerController::OnPreSimulationTickCheckDesync(ASimulationManager* SimulationManager) {
}


void ALocCorePlayerController::LocSimulateNetworkFailure() {
}

void ALocCorePlayerController::LocSimulateDesync() {
}

float ALocCorePlayerController::GetStreamingSaveGameFragmentProgress() const {
    return 0.0f;
}

int32 ALocCorePlayerController::GetStreamingSaveGameFragmentNum() const {
    return 0;
}

bool ALocCorePlayerController::GetIsStreamingSaveGame() const {
    return false;
}

void ALocCorePlayerController::GatherDesyncReportAndSendToClient() {
}

void ALocCorePlayerController::ClientUpdateSaveGameStreamInfo_Implementation(bool bIsStreaming, int32 TotalFragmentCount) {
}

void ALocCorePlayerController::ClientRequestPlayerUniqueId_Implementation() {
}

void ALocCorePlayerController::ClientReceiveSerializedSimulation_Implementation(uint32 FrameNumber, const FSimulationHashRecordFragmentContainer& ServerHashes) {
}

void ALocCorePlayerController::ClientPong_Implementation(double PingTime) {
}

void ALocCorePlayerController::ClientOnGameStartedStreamFinished_Implementation(int32 TargetPlayerNum) {
}

void ALocCorePlayerController::ClientDistributeCommands_Implementation(const TArray<uint8>& SyncRecords) {
}

void ALocCorePlayerController::ClientAckCommands_Implementation(bool bIsAckAck, const TArray<uint32>& SyncRecords) {
}

void ALocCorePlayerController::CheckDesyncReport(uint32 FrameNumber) {
}

void ALocCorePlayerController::AddSyncSimulationCommand(const FSimulationCommandFrameRecord& Record) {
}


