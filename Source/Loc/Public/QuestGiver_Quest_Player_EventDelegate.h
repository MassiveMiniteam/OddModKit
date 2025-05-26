#pragma once
#include "CoreMinimal.h"
#include "QuestGiver_Quest_Player_EventDelegate.generated.h"

class AQuestInstance;
class ASimulationPlayer;
class UQuestGiverSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FQuestGiver_Quest_Player_Event, UQuestGiverSimulationComponent*, Component, AQuestInstance*, QuestInstance, ASimulationPlayer*, SimulationPlayer);

