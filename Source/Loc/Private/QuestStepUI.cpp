#include "QuestStepUI.h"

UQuestStepUI::UQuestStepUI() : UUserWidget(FObjectInitializer::Get()) {
    this->QuestStepBehaviour = NULL;
    this->bOnlyUpdateOnce = false;
    this->bUseDarkMode = false;
}


