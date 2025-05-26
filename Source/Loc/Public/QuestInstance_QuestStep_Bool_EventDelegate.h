#pragma once
#include "CoreMinimal.h"
#include "QuestInstance_QuestStep_Bool_EventDelegate.generated.h"

class AQuestInstance;
class UQuestStepBehaviour;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FQuestInstance_QuestStep_Bool_Event, AQuestInstance*, QuestInstance, UQuestStepBehaviour*, QuestStepBehaviour, bool, bState);

