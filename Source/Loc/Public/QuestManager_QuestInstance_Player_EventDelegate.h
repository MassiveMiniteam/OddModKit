#pragma once
#include "CoreMinimal.h"
#include "QuestManager_QuestInstance_Player_EventDelegate.generated.h"

class AQuestInstance;
class ASimulationPlayer;
class UQuestManagerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FQuestManager_QuestInstance_Player_Event, UQuestManagerSimulationComponent*, QuestManagerSimulationComponent, AQuestInstance*, QuestInstance, ASimulationPlayer*, SimulationPlayer);

