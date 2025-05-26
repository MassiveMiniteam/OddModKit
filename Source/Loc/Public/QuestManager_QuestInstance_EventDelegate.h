#pragma once
#include "CoreMinimal.h"
#include "QuestManager_QuestInstance_EventDelegate.generated.h"

class AQuestInstance;
class UQuestManagerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQuestManager_QuestInstance_Event, UQuestManagerSimulationComponent*, QuestManagerSimulationComponent, AQuestInstance*, QuestInstance);

