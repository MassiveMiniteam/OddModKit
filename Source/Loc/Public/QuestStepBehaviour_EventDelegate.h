#pragma once
#include "CoreMinimal.h"
#include "QuestStepBehaviour_EventDelegate.generated.h"

class UQuestStepBehaviour;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FQuestStepBehaviour_Event, UQuestStepBehaviour*, QuestStepBehaviour);

