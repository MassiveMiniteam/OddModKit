#include "ReplaceOnQuestStartComponent.h"

UReplaceOnQuestStartComponent::UReplaceOnQuestStartComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->QuestConfig = NULL;
    this->QuestManager = NULL;
}

void UReplaceOnQuestStartComponent::OnNewQuestAccepted(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* QuestInstance) {
}

void UReplaceOnQuestStartComponent::OnItemUnlocked(UUnlockableDataAsset* UnlockableDataAsset) {
}


