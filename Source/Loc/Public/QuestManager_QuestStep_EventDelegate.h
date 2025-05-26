#pragma once
#include "CoreMinimal.h"
#include "QuestManager_QuestStep_EventDelegate.generated.h"

class UQuestManagerSimulationComponent;
class UQuestStepBehaviour;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQuestManager_QuestStep_Event, UQuestManagerSimulationComponent*, QuestManager, UQuestStepBehaviour*, QuestStep);

