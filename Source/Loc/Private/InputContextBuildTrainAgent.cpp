#include "InputContextBuildTrainAgent.h"

UInputContextBuildTrainAgent::UInputContextBuildTrainAgent() {
    this->CursorInputContext = NULL;
    this->GamepadMovementInputContext = NULL;
    this->PreviewActor = NULL;
    this->CachedHoveredRail = NULL;
    this->CachedHoveredTrainAgent = NULL;
    this->TrainAgentConfig = NULL;
    this->MouseHitSphereRadius = 200.00f;
    this->InputAction_Place = NULL;
    this->InputAction_Destroy = NULL;
    this->InputAction_Rotate = NULL;
    this->InputAction_Cancel = NULL;
    this->GamepadMovementInputContextClass = NULL;
    this->CursorActorClass = NULL;
    this->ConstructableConfigRails = NULL;
    this->TickHoveredPoleConnection = NULL;
}

void UInputContextBuildTrainAgent::SetConstructableConfig(UConstructableConfig* Config) {
}



void UInputContextBuildTrainAgent::OnInputAction_Rotate(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextBuildTrainAgent::OnInputAction_Place(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextBuildTrainAgent::OnInputAction_Destroy(UInputActionData* InputAction, ALocPlayerController* Player) {
}

void UInputContextBuildTrainAgent::OnInputAction_Cancel(UInputActionData* InputAction, ALocPlayerController* Player) {
}

UConstructableConfig* UInputContextBuildTrainAgent::GetCurrentConfig() const {
    return NULL;
}

AActor* UInputContextBuildTrainAgent::FindHoveredTrainAgent() const {
    return NULL;
}

AActor* UInputContextBuildTrainAgent::FindHoveredRail() const {
    return NULL;
}


