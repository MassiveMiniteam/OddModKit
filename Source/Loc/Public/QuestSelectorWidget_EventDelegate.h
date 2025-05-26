#pragma once
#include "CoreMinimal.h"
#include "QuestSelectorWidget_EventDelegate.generated.h"

class UNPCQuestSelectorWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FQuestSelectorWidget_Event, UNPCQuestSelectorWidget*, QuestSelectorWidget);

