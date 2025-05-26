#include "LocPlayerController.h"

ALocPlayerController::ALocPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bShowMouseCursor = true;
    this->ClickEventKeys.AddDefaulted(1);
    this->DefaultMouseCursor = EMouseCursor::Crosshairs;
    this->UIPlayer = NULL;
    this->SpawnPlayerCommandType = NULL;
    this->MoveSpeed = 1000.00f;
    this->SimulationPlayer = NULL;
    this->bIsCursorEnabled = false;
}

void ALocPlayerController::UpdateVibrationSupport(UInputDeviceMapping* CurrentDevice) {
}

void ALocPlayerController::UnsubscribeInputDeviceChange() {
}

void ALocPlayerController::SubscribeInputDeviceChange() {
}

void ALocPlayerController::SetCursorEnabled(bool bState) {
}

void ALocPlayerController::ServerAnswerModList_Implementation(const TArray<FModManifestShort>& Mods) {
}

void ALocPlayerController::OnSimulationPlayerSet_Implementation(ASimulationPlayer* InSimulationPlayer) {
}

void ALocPlayerController::OnLoadingDone() {
}

void ALocPlayerController::OnInputDeviceChanged(UInputDeviceMapping* InputDevice) {
}


void ALocPlayerController::MarkKeyConsumedThisFrame(FKey Key) {
}

void ALocPlayerController::IsConsumedKeyThisFrame(FKey Key, EBranchInputConsumedType& OutBranches) {
}

UUIPlayerEntity* ALocPlayerController::GetUIPlayer() const {
    return NULL;
}

FIntVector ALocPlayerController::GetPlayerSpawnPosition_Implementation() {
    return FIntVector{};
}

void ALocPlayerController::ClientRequestModList_Implementation() {
}


