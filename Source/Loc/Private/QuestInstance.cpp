#include "QuestInstance.h"
#include "SimulationTimerComponent.h"
#include "StatsComponent.h"

AQuestInstance::AQuestInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnableTick = true;
    this->StatsComponent = CreateDefaultSubobject<UStatsComponent>(TEXT("StatsComponent"));
    this->AutoCompleteTimerComponent = CreateDefaultSubobject<USimulationTimerComponent>(TEXT("AutoCompleteTimerComponent"));
    this->QuestData = NULL;
    this->QuestGiverComponent = NULL;
    this->QuestManager = NULL;
}

void AQuestInstance::SetQuestGiverComponent(UQuestGiverSimulationComponent* InQuestGiverComponent) {
}

void AQuestInstance::OnCompleteQuestTimerFired(USimulationTimerComponent* SimulationTimerComponent) {
}

void AQuestInstance::OnAnyQuestStepStateChanged(UQuestStepBehaviour* QuestStepBehaviour, bool bState) {
}

UQuestGiverSimulationComponent* AQuestInstance::GetQuestGiverComponent() const {
    return NULL;
}

UQuestConfig* AQuestInstance::GetQuestData() const {
    return NULL;
}

TArray<ASimulationPlayer*> AQuestInstance::GetPlayers() {
    return TArray<ASimulationPlayer*>();
}

bool AQuestInstance::CanComplete(ASimulationPlayer* SimulationPlayer) {
    return false;
}

void AQuestInstance::AutoComplete() {
}


