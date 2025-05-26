#include "ReplaceSelfOnQuestGiverCompleteComponent.h"

UReplaceSelfOnQuestGiverCompleteComponent::UReplaceSelfOnQuestGiverCompleteComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->QuestGiverComponent = NULL;
    this->ReplacingClass = NULL;
}

void UReplaceSelfOnQuestGiverCompleteComponent::Unlock_Debug() {
}

void UReplaceSelfOnQuestGiverCompleteComponent::OnQuestCompleted(UQuestGiverSimulationComponent* QuestGiver, AQuestInstance* QuestInstance, ASimulationPlayer* SimulationPlayer) {
}


