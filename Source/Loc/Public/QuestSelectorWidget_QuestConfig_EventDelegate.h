#pragma once
#include "CoreMinimal.h"
#include "QuestSelectorWidget_QuestConfig_EventDelegate.generated.h"

class UNPCQuestSelectorWidget;
class UQuestConfig;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQuestSelectorWidget_QuestConfig_Event, UNPCQuestSelectorWidget*, QuestSelectorWidget, UQuestConfig*, QuestConfig);

