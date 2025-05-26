#include "MonumentQuestHandler.h"

UMonumentQuestHandler::UMonumentQuestHandler(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UnlockHandler = NULL;
    this->QuestGiverComponent = NULL;
    this->QuestManager = NULL;
    this->bRefreshAvailableQuestsNextTick = false;
}

void UMonumentQuestHandler::OnItemUnlocked(UUnlockableDataAsset* UnlockableDataAsset) {
}


