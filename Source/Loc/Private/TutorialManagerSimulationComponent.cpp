#include "TutorialManagerSimulationComponent.h"

UTutorialManagerSimulationComponent::UTutorialManagerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->QuestManager = NULL;
    this->TutorialUnlockable = NULL;
    this->FirstQuestAfterTutorial = NULL;
    this->ActiveQuestConfig = NULL;
    this->TutorialStepIndex = 0;
    this->WaitIntervalBetweenTutorialSteps = 3.00f;
    this->TutorialStepsTimer = NULL;
}

void UTutorialManagerSimulationComponent::StartTutorialFromBeginning() {
}

void UTutorialManagerSimulationComponent::OnUnlock(UUnlockableDataAsset* UnlockableDataAsset) {
}

void UTutorialManagerSimulationComponent::OnTutorialStepsDelayTimerFired(USimulationTimerComponent* SimulationTimerComponent) {
}


void UTutorialManagerSimulationComponent::OnQuestCompleted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer) {
}

bool UTutorialManagerSimulationComponent::IsTutorialFinished() {
    return false;
}

bool UTutorialManagerSimulationComponent::IsTutorialEnabled() {
    return false;
}

UTutorialManagerSimulationComponent* UTutorialManagerSimulationComponent::Get(UObject* WorldContext) {
    return NULL;
}

void UTutorialManagerSimulationComponent::ContinueOrStartTutorial() {
}


