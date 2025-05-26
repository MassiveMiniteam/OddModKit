#include "LocGameMode.h"

ALocGameMode::ALocGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bBlockIncomingJoinRequests = false;
    this->FrameToSerializeState = 0;
    this->bIsWaitingForPlayerLoad = false;
    this->LastLogoutFrame = 0;
    this->SerializedStateToJoin = NULL;
    this->bIsInited = false;
}

void ALocGameMode::PostLoginWaitForCharacterSpawn(APlayerController* NewPlayer) {
}

void ALocGameMode::OnPostSimulationTick(ASimulationManager* SimulationManager) {
}


void ALocGameMode::HandlePlayerLogin(APlayerController* NewPlayer) {
}

bool ALocGameMode::GetIsSessionCreationAllowed_Implementation() {
    return false;
}

bool ALocGameMode::GetIsPresenceJoinAllowed_Implementation() {
    return false;
}

ULocCoreSaveGame* ALocGameMode::CreateEditorSavegame_Implementation() {
    return NULL;
}


