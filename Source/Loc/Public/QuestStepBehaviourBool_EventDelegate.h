#pragma once
#include "CoreMinimal.h"
#include "QuestStepBehaviourBool_EventDelegate.generated.h"

class UQuestStepBehaviour;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQuestStepBehaviourBool_Event, UQuestStepBehaviour*, QuestStepBehaviour, bool, bState);

