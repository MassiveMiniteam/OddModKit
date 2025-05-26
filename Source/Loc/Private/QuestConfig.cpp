#include "QuestConfig.h"
#include "QuestInstance.h"

UQuestConfig::UQuestConfig() {
    this->Tier = EQuestTier::Tier1;
    this->QuestInstanceType = AQuestInstance::StaticClass();
    this->InitialDialogueConfig = NULL;
    this->AcceptedDialogueConfig = NULL;
    this->ReminderDialogueConfig = NULL;
    this->SuccessDialogueConfig = NULL;
    this->QuestGiverType = NULL;
    this->bUsesInventory = false;
    this->bIsRepeatable = false;
    this->bCanCompleteSelf = false;
    this->bAutomaticallyStartIfPrerequisitesMet = false;
    this->bOnlyAutostartIfTutorial = false;
    this->bPinOnAutostart = false;
    this->Achievement = NULL;
    this->bHiddenInJournal = false;
    this->bHiddenInOverview = false;
    this->bShowAsAvailableInOverview = false;
    this->bHiddenInQuestToasts = false;
    this->bIsMainline = true;
    this->VisualSortIndex = 0;
    this->QuestOverviewCategory = NULL;
    this->QuestCompleteWidget = NULL;
    this->QuestRewardModalType = NULL;
    this->OverrideNPCInventoryWidget = NULL;
}

bool UQuestConfig::IsInDemo() const {
    return false;
}


