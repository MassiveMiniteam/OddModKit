#include "LocCoreCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Net/UnrealNetwork.h"

ALocCoreCharacter::ALocCoreCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    
}

void ALocCoreCharacter::ServerSetLocPlayerId_Implementation(FLocPlayerId LocalPlayerId) {
}

void ALocCoreCharacter::OnLocPlayerIdReplicated() {
}

void ALocCoreCharacter::ClientSetLocPlayerId_Implementation(FLocPlayerId LocalPlayerId) {
}

void ALocCoreCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ALocCoreCharacter, LocPlayerId);
}


