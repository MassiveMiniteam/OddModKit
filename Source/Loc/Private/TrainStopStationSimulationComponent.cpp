#include "TrainStopStationSimulationComponent.h"

UTrainStopStationSimulationComponent::UTrainStopStationSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Mode = ETrainStopStationMode::Timer;
    this->bPlayerManualStopTriggered = false;
    this->PoleComponent = NULL;
    this->StopLocomotiveGameplayEffect = NULL;
}

void UTrainStopStationSimulationComponent::SetTimerDuration(FFixed NewTimerDuration) {
}

void UTrainStopStationSimulationComponent::OnLogicSignalChanged(ULogicConnectionSimulationComponent* Input) {
}

void UTrainStopStationSimulationComponent::OnGameplayEffectRemoved() {
}

void UTrainStopStationSimulationComponent::OnAgentStartsMoving(const UTrainTracksPoleBaseSimulationComponent* Pole, const UTrainTracksAgentSimulationComponent* Agent) {
}

void UTrainStopStationSimulationComponent::OnAgentArrives(const UTrainTracksPoleBaseSimulationComponent* Pole, const UTrainTracksAgentSimulationComponent* Agent) {
}

bool UTrainStopStationSimulationComponent::IsPlayerCustomBlockActive() const {
    return false;
}

bool UTrainStopStationSimulationComponent::IsLocomotiveHereWaiting() const {
    return false;
}

bool UTrainStopStationSimulationComponent::IsCurrentlyStoppingIncomingLocomotives() const {
    return false;
}

bool UTrainStopStationSimulationComponent::IsConnectedToAnyLogicInput() const {
    return false;
}

bool UTrainStopStationSimulationComponent::IsBlockedByLogic() const {
    return false;
}

FFixed UTrainStopStationSimulationComponent::GetTimerDuration() const {
    return FFixed{};
}

FFixed UTrainStopStationSimulationComponent::GetRelativeCargoAmountOfCompleteTrain() const {
    return FFixed{};
}

ETrainStopStationMode UTrainStopStationSimulationComponent::GetMode() const {
    return ETrainStopStationMode::Timer;
}

void UTrainStopStationSimulationComponent::ChangeMode(ETrainStopStationMode NewMode) {
}

bool UTrainStopStationSimulationComponent::AnyLogicInputBlocks() const {
    return false;
}


