#include "LocCharacter.h"
#include "Templates/SubclassOf.h"

ALocCharacter::ALocCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GravitiyScaleAtGameStart = 4.00f;
    this->MinimumZPositionToTeleport = -50000.00f;
    this->bIsTeleporting = false;
    this->bHideLoadingScreenOnTeleportDone = false;
    this->TeleportGroundCheckDelay = 0.00f;
}

void ALocCharacter::TeleportStartEffectEvent_Implementation(FIntVector Location) {
}

void ALocCharacter::TeleportCharacterToTop() {
}

void ALocCharacter::TeleportCharacterToPositionOnDialogueOver(UDialoguePlayerComponent* DialoguePlayerComponent, FVector position, FRotator Rotation) {
}

void ALocCharacter::TeleportCharacterToClosestActorOfType(TSubclassOf<ASimulationActor> ActorClass, bool bShowLoadingScreen) {
}

void ALocCharacter::TeleportCharacterTo(FVector position, FRotator Rotation, bool bSnapToTerrain, bool bShowLoadingScreen) {
}


void ALocCharacter::OnTeleportDone() {
}

void ALocCharacter::OnDialoguePlayed(UDialoguePlayerComponent* DialoguePlayer, UDialogueConfig* Dialogue) {
}

void ALocCharacter::LocRestartRVT() {
}

void ALocCharacter::EnableGravity() {
}

void ALocCharacter::DisableMovementComponentReplication() {
}

void ALocCharacter::DisableGravity() {
}


