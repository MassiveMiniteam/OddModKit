#pragma once
#include "CoreMinimal.h"
#include "DialogueQuestPrompt_EventDelegate.generated.h"

class UDialogueQuestPromptWidget;
class UQuestConfig;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDialogueQuestPrompt_Event, UDialogueQuestPromptWidget*, Widget, UQuestConfig*, QuestConfig);

