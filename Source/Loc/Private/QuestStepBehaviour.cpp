#include "QuestStepBehaviour.h"

UQuestStepBehaviour::UQuestStepBehaviour() {
    this->QuestStepUIType = NULL;
    this->bIndividualCompletionCheckPerPlayer = false;
    this->bIsOptional = false;
    this->bRememberSuccess = true;
    this->bCompletedSuccessful = false;
    this->QuestInstance = NULL;
    this->TargetMarkerClass = NULL;
    this->TargetMarker = NULL;
}

void UQuestStepBehaviour::UpdateSuccessState(bool bSuccess) {
}

void UQuestStepBehaviour::SetCompletionStatePerPlayer(ASimulationPlayer* InPlayer, bool bState) {
}






void UQuestStepBehaviour::OnQuestUnpinned(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* UnpinnedQuestInstance) {
}

void UQuestStepBehaviour::OnQuestStepSuccessStateChanged_Event_Implementation(bool bSucces) {
}

void UQuestStepBehaviour::OnQuestPinned(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* PinnedQuestInstance) {
}

void UQuestStepBehaviour::OnPlayerLeft(ASimulationActor* Player) {
}

void UQuestStepBehaviour::OnPlayerJoined(ASimulationActor* Player) {
}

void UQuestStepBehaviour::OnPlayerIdentificationChanged(UPlayerIdentificationSimulationComponent* PlayerIdentificationComponent) {
}



void UQuestStepBehaviour::NotifyUpdatesForPresentation(bool bHasChangedSinceLastTime) {
}

FText UQuestStepBehaviour::GetTitleText_Implementation(bool bCompleted) {
    return FText::GetEmpty();
}

FText UQuestStepBehaviour::GetDescriptionText_Implementation() {
    return FText::GetEmpty();
}

bool UQuestStepBehaviour::Editor_SupportsIndividualCheckPerPlayer_Implementation() {
    return false;
}

bool UQuestStepBehaviour::CanCompleteIgnoreOptional(ASimulationPlayer* SimulationPlayer) {
    return false;
}

bool UQuestStepBehaviour::CanComplete(ASimulationPlayer* SimulationPlayer) {
    return false;
}



