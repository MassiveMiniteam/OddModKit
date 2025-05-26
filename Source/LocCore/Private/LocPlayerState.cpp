#include "LocPlayerState.h"
#include "Net/UnrealNetwork.h"

ALocPlayerState::ALocPlayerState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsSimulationReady = false;
    this->bIsLoggingIn = false;
}

void ALocPlayerState::SetLocPlayerId(FLocPlayerId ID) {
}

FLocPlayerId ALocPlayerState::GetLocPlayerId() const {
    return FLocPlayerId{};
}

void ALocPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ALocPlayerState, LocPlayerId);
    DOREPLIFETIME(ALocPlayerState, bIsSimulationReady);
    DOREPLIFETIME(ALocPlayerState, bIsLoggingIn);
}


