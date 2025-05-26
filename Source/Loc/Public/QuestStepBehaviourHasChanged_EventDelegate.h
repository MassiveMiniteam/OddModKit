#pragma once
#include "CoreMinimal.h"
#include "QuestStepBehaviourHasChanged_EventDelegate.generated.h"

class UQuestStepBehaviour;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQuestStepBehaviourHasChanged_Event, UQuestStepBehaviour*, QuestStepBehaviour, bool, bStateHasChanged);

