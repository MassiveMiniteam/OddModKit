#include "LocGameplayPlayerController.h"

ALocGameplayPlayerController::ALocGameplayPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ClickEventKeys.AddDefaulted(1);
    this->OpenInventoryAction = NULL;
    this->OpenBuildMenuAction = NULL;
    this->OpenPathToolAction = NULL;
    this->OpenTechTreeAction = NULL;
    this->OpenRelocateToolAction = NULL;
    this->OpenMapAction = NULL;
    this->OpenJournalAction = NULL;
    this->OpenGlossaryAction = NULL;
    this->OpenCopyToolAction = NULL;
}


void ALocGameplayPlayerController::OnOpenTechTree_Implementation(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
}

void ALocGameplayPlayerController::OnOpenRelocateTool_Implementation(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
}

void ALocGameplayPlayerController::OnOpenPauseMenu_Implementation(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
}

void ALocGameplayPlayerController::OnOpenPathTool_Implementation(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
}

void ALocGameplayPlayerController::OnOpenMap_Implementation(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
}

void ALocGameplayPlayerController::OnOpenJournal_Implementation(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
}

void ALocGameplayPlayerController::OnOpenInventory_Implementation(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
}

void ALocGameplayPlayerController::OnOpenGlossary_Implementation(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
}

void ALocGameplayPlayerController::OnOpenCopyTool_Implementation(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
}

void ALocGameplayPlayerController::OnOpenBuildMenu_Implementation(UInputActionData* InputAction, ALocPlayerController* PlayerController) {
}



