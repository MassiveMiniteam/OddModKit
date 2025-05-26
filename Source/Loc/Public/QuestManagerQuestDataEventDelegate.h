#pragma once
#include "CoreMinimal.h"
#include "QuestManagerQuestDataEventDelegate.generated.h"

class ASimulationPlayer;
class UQuestConfig;
class UQuestManagerSimulationComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FQuestManagerQuestDataEvent, UQuestManagerSimulationComponent*, QuestManagerSimulationComponent, UQuestConfig*, QuestData, ASimulationPlayer*, SimulationPlayer);

