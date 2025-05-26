#include "LocCoreGameState.h"
#include "Net/UnrealNetwork.h"

ALocCoreGameState::ALocCoreGameState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bSpawnSimulation = true;
    this->bSpawnScheduler = true;
    this->bSpawnNetworkManager = true;
    this->SimulationManager = NULL;
    this->SimulationScheduler = NULL;
    this->bShowLoadingScreen = false;
    this->SaveGameClass = NULL;
}

void ALocCoreGameState::ServerUpdatePlayerPUID_Implementation(FPlayerPUIDPair PlayerPUIDPair) {
}
bool ALocCoreGameState::ServerUpdatePlayerPUID_Validate(FPlayerPUIDPair PlayerPUIDPair) {
    return true;
}

void ALocCoreGameState::OnRep_ShowLoadingScreen() {
}

ASimulationScheduler* ALocCoreGameState::GetSimulationScheduler() const {
    return NULL;
}

ASimulationManager* ALocCoreGameState::GetSimulationManager() const {
    return NULL;
}

FString ALocCoreGameState::GetPlayerPUID(APlayerState* PlayerState) const {
    return TEXT("");
}

ANetworkManager* ALocCoreGameState::GetNetworkManager() {
    return NULL;
}

void ALocCoreGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ALocCoreGameState, bShowLoadingScreen);
    DOREPLIFETIME(ALocCoreGameState, PlayerPUIDsArray);
}


